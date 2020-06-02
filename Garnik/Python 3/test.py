from selenium import webdriver
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
chrome_options.add_extension('/Users/garnik/Library/Application Support/Google/Chrome/Default/Extensions/fploionmjgeclbkemipmkogoaohcdbig')

hyperlink = "https://www.coolmathgames.com/"
driver = webdriver.Chrome()
driver.get(hyperlink)
 
navigationStart = driver.execute_script("return window.performance.timing.navigationStart")
responseStart = driver.execute_script("return window.performance.timing.responseStart")
domComplete = driver.execute_script("return window.performance.timing.domComplete")

backendPerformance_calc = responseStart - navigationStart
frontendPerformance_calc = domComplete - responseStart
 
# print("Back End: %s" % backendPerformance_calc)
print("The Load time is: {:.2f}".format(frontendPerformance_calc))
 
driver.quit()