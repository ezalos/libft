# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_master_head.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/23 19:04:48 by ldevelle          #+#    #+#              #
#    Updated: 2020/06/28 23:31:55 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extension=.h
extension_sec=_H
file_name=auto_
anti_dot=$(echo "${2//.}")
file=$file_name$2$extension
spe=$file_name$anti_dot$extension_sec
path=$1$file

# rm -rf $path
echo file $file
echo path $path
echo spe $spe

if [ "$(uname)" == "Darwin" ]; then
	echo -n "#ifndef " > $path
	printf $spe | awk '{ print toupper($1) }' >> $path
	echo -n "# define " >> $path
	printf $spe | awk '{ print toupper($1) }' >> $path
	echo "" >> $path
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	echo -n "#ifndef " > $path
	printf $spe | awk '{ print toupper($1) }' >> $path
	echo -n "# define " >> $path
	printf $spe | awk '{ print toupper($1) }' >> $path
	echo "" >> $path
fi

find includes/auto -type f | sed 's~includes/auto~# include "auto~g' | sed 's~\.h~\.h"~g' >> $path

echo '' >> $path
echo '#endif' >> $path

vim -c :Stdheader -c:wq $path
