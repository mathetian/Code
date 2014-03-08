# -*- coding:utf-8 -*-
import codecs
import sys

sys.stdout = codecs.getwriter("utf-8")(sys.stdout)
print u"にほんご"

sysCharType = sys.getfilesystemencoding()  
print sysCharType

file = codecs.open("hello", 'w', encoding='utf-8')
file.write(u"にほんご")

file1 = open("hello2", "w")
file1.write("にほんご")
