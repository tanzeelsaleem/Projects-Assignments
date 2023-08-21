from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import Select
import os
import requests
import time

driver = webdriver.Chrome('C:\Program Files\chromedriver_win32\chromedriver.exe')
driver.get("https://www.supremecourt.gov.pk/judgement-search/#1573035933449-63bb4a39-ac81")


with open("Judgements Details.txt", "a") as file1:
    file1.write(f"Category\t S. No.\t Abstract of Judgement\n")
    
    tags = ["C.A.", "C.M.A.", "C.P.", "Const.P.", "Crl.A.", "Crl.P."]
    tag = Select(driver.find_element(by=By.ID, value='case_type'))
    for optionTag in tag.options:
        optionValue = optionTag.get_attribute('value')
        if (optionValue in tags):
            tag.select_by_value(optionValue)
            button = driver.find_element(by=By.XPATH, value="//input[@type='button' and @value='Search Result']")
            button.click()

            time.sleep(10)
            
            for i in range(5):
                table = driver.find_element(By.XPATH, '//table[@id="resultsTable"]')
                rows = table.find_elements(By.CSS_SELECTOR, "tr.odd:not([style='background:#fbfbfb']), tr.even:not([style='background:#fbfbfb'])")
                for row in rows:
                    cells = row.find_elements(By.CSS_SELECTOR, 'td:nth-child(1)')
                    for cell in cells:
                        print(cell.text)
                for row in rows:
                    td1, td4, td5, td7 = row.find_elements(By.CSS_SELECTOR, "td:nth-child(1), td:nth-child(4), td:nth-child(5), td:nth-child(7)")
                    file1.writelines(f"{optionValue}\t\t{td1.text}\t\t {td4.text}, {td5.text}, {td7.text}\n")
                with open("PDF_Links.txt", "a") as file2:
                    for row in rows:
                        td10 = row.find_element(By.CSS_SELECTOR, "td:nth-child(10)")
                        links = td10.find_elements(By.CSS_SELECTOR, "a")
                        for link in links:
                            if link.get_attribute("href").endswith(".pdf"):
                                file2.write(f"{link.get_attribute('href')}\n")
                clickButton = driver.find_element(by=By.XPATH, value="//a[text()='Next']")
                clickButton.click()
                time.sleep(1)

with open('PDF_Links.txt', 'r') as file:
    for line in file:
        filename = line.strip().split('/')[-1]
        response = requests.get(line.strip())
        with open(os.path.join('C:/Users/mtanz/Downloads/Judgments', filename), 'wb') as pdfFile:
            pdfFile.write(response.content)
            
        print(f'{filename} downloaded successfully.')