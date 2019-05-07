# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_mk_srcs.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:03:06 by ldevelle          #+#    #+#              #
#    Updated: 2019/05/07 13:14:25 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

# Create a .mk file with every .c listed inside $2$1

# usage:	sh get_mk_srcs terminal ../srcs/minishell/
# $1 (terminal) will be the name of directory of interest
# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
# $2 is fully optional

path=mk_dependencies/
prefix=PAT/pat_
spre=SRC/src_
ppre=DIR/dir_
extension=.mk
name=$path$prefix$1$extension
name2=$path$ppre$1$extension
name1=$path$spre$1$extension

rm -rf $name $name1 $name2
touch $name $name1 $name2


# Creation .mk with full path to the file
find $3$2$1 -type f -exec ls -lrt -d -1 {} \+ | grep '\.c' >> $name

sed -i '' 's/$/ \\/' $name
sed -i '' 's/^/	/' $name
sed -i '' "1s/^/PAT += /" $name
sed -i '' '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name

# Creation .mk with name of the file
cat $name | rev | cut -d '/' -f 1 | rev | cut -d ' ' -f 1 >> $name1

sed -i '' 's/$/ \\/' $name1
sed -i '' 's/^/	/' $name1
sed -i '' "1s/^/SRC += /" $name1
sed -i '' '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name1

# Creation .mk with path without file at the end
cat $name | cut -d$'\t' -f 2 | cut -d '.' -f 1 | cut -d '_' -f 1 | sed "s~ft~~g" >> $name2

sed -i '' 's/$/ \\/' $name2
sed -i '' 's/^/	/' $name2
sed -i '' "1s/^/DIR += /" $name2
sed -i '' '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name2


# echo "$1\t\tconverted to Makefile source"
