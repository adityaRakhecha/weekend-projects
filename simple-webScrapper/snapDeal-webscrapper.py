#requests library to download the page
import requests as req

#beautifulSoup to parse the document(webpage)
from bs4 import BeautifulSoup as bs4

#Pandas to combine the data
import pandas as pd

#GET request to web server
page = req.get("https://www.snapdeal.com/products/appliances-air-conditioners?sort=plrty&showAds=false")


#Parsing the webpage
html = bs4(page.content, 'html.parser')

#Getting the title of every product listed
title = [t.get_text() for t in html.select(".product-title")]

#Getting the cost price of every product
prod = html.find_all(class_="lfloat product-desc-price strike ")
Cprods = [pt.get_text() for pt in prod]

#Getting the discounted price of evry product
dprod = html.find_all(class_="lfloat product-price")
Dprods = [pt.get_text() for pt in dprod]

#Getting the % of discount of every product
disc = html.select(".product-discount span")
discnt = [t.get_text() for t in disc]

#Combining the data fetched into a Pandas DataFrame
names = pd.DataFrame({
	"TITLE": title,
	#Pandas can hold upto 3 columns	
	#"C_Price": Cprods,
	"D_Price": Dprods,
	"P_Discount": discnt
	})
  
#Finally print the data
print(names)


