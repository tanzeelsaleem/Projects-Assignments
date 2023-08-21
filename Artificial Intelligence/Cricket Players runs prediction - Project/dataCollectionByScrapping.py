import requests
from bs4 import BeautifulSoup
import csv


response = requests.get('https://stats.espncricinfo.com/ci/content/records/284269.html')

soup = BeautifulSoup(response.content, 'html.parser')

table = soup.find('table')
thead = table.find('thead')
tr = thead.find('tr')

with open('Players.csv', mode='w') as csvfile:
    head = []
    for th in tr.find_all('th'):
        head.append(th.get_text())

    writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    writer.writerow(head)

    body = []
    tbody = table.find('tbody')
    for tr in tbody.find_all('tr'):  
        for td in tr.find_all('td'):
            body.append(td.get_text())
        if(body!='\n'):
            writer.writerow(body)
            body.clear()