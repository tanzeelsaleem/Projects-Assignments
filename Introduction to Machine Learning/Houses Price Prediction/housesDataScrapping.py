import requests
from bs4 import BeautifulSoup
import pandas as pd
import csv

price = []
location = []
bedrooms = []
baths = []
area = []
for x in range(7):
  url = "https://www.zameen.com/Houses_Property/Islamabad_Bahria_Town-383-"+str(x+1)+".html"

  page = requests.get(url)
  soup = BeautifulSoup(page.content, 'html5')
  
  p = soup.findAll(class_="f343d9ce")
  price+=p

  l = soup.find_all(attrs={"aria-label": "Location"})
  location+=l

  b = soup.find_all(attrs={"aria-label": "Beds"})
  bedrooms+=b

  ba = soup.find_all(attrs={"aria-label": "Baths"})
  baths+=ba

  a = soup.find_all(attrs={"aria-label": "Area"})
  area+=a


with open('Houses.csv', mode='w') as csvfile:
    head = ['Location','Area (Marla)','Beds','Baths','Price (PKR:Crore)']

    writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    writer.writerow(head)

    body = []

    for x in range (len(price)):
      body.append(location[x].get_text())

      split_str = area[x].get_text().split()
      numeric_value = split_str[0]
      unit = split_str[1]
      if numeric_value.isdigit():
        output = int(numeric_value)
      elif numeric_value.isdecimal():
        output = float(numeric_value)
      if unit == "Kanal":
        output*=20
      body.append(output)

      body.append(int(bedrooms[x].get_text()))
      body.append(int(baths[x].get_text()))

      sstr = price[x].get_text().split()
      nvalue = sstr[0]
      body.append(float(nvalue))

      writer.writerow(body)
      body.clear()