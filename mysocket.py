import socket
#import urllib.request, urllib.parse, urllib.error

page = str(input('Enter URL "example.com": '))
x = page.find('/')
site = page[0:x]
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((site,80))
cmd = 'GET ' + site + ' HTTP/1.0\n\n'
cmd = cmd.encode()
sock.send(cmd)

while True:
    data = sock.recv(512)
    if (len(data) < 1):
       break
    print(data.decode())
sock.close()


#fhand = urllib.request.urlopen(input('Enter URL: '))
#for line in fhand:
#    print(line.decode().strip())