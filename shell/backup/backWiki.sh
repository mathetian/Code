#!/bin/bash

nowtime=`date +%y%m%d%H%M`
sqlFile="mediaWiki.sql"
base="/var/LabMediaWiki"
base2="/var/www/wiki"

cd /var/LabMediaWiki
cp $base2/* .
cp -R $base2/bin .
cp -R $base2/cache .
cp -R $base2/docs .
cp -R $base2/includes .
cp -R $base2/languages .
cp -R $base2/maintenance .
cp -R $base2/mw-config .
cp -R $base2/resources .
cp -R $base2/serialized .
cp -R $base2/skins .
cp -R $base2/tests .
cp -R $base2/images .
mysqldump -uroot -p123456 my_wiki > $sqlFile
git pull originTyl master
git add -A
git commit -a -m $nowtime
git push originTyl master
