import requests

domain = input('Input domain name: ')
file = open('/home/jason/python/subdomains.txt', 'r')
content = file.read()
subdomains = content.splitlines()

for subdomain in subdomains:
    url = f'http://{subdomain}.{domain}'
    try:
        requests.get(url)
    except requests.ConnectionError:
        pass
    else:
        print('Hit on Subdomain: ', url)