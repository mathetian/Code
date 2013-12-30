#coding=utf8

import urllib2
import re

"""
Login to Sina Weibo with cookie
"""

COOKIE = '' #fill with your weibo.com cookie
HEADERS = {"cookie": ""}

def test_login():
    url = 'http://weibo.com/xx/xx'
    req = urllib2.Request(url, headers=HEADERS)
    text = urllib2.urlopen(req).read()
    print text
    pat_title = re.compile('<title>(.+?)</title>')
    r = pat_title.search(text)
    if r:
        print r.group(1)


if __name__ == '__main__':
    test_login()
