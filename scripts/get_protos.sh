# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_protos.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:02:24 by ldevelle          #+#    #+#              #
#    Updated: 2019/03/22 23:09:48 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

# Create a header file with every .c inside $2$1

# usage:	sh get_protos terminal ../srcs/minishell/
# $1 (terminal) will be the name of directory of interest
# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
# $2 is fully optional

path=includes/auto/
prefix=auto_
suffix=_H
extension=.h
name=$path$prefix$1$extension
spe=$prefix$1$suffix

echo "#ifndef AUTO_\c" > $name
printf $spe | awk '{ print toupper($1) }' >> $name
echo "# define AUTO_\c" >> $name
printf $spe | awk '{ print toupper($1) }' >> $name
echo "" >> $name

find $3$2$1 -type f -exec cat {} \+ |
grep -e int -e char -e void -e size_t -e t_list |
grep ft_ |
grep -v -e ":+:" -e static -e while -e if -e ";" -e "#include " -e "=" -e "->" |
tr -s '\t' '\t\t' |
sort >> $name
sed -i '' "s~)$~);~g" $name
sed -i '' "s~	~		~g" $name
sed -i '' "s~int	~int		~g" $name
sed -i '' "s~intmax_t	~intmax_t~g" $name

echo "\n#endif" >> $name

echo "includes/auto_$1.h created"
