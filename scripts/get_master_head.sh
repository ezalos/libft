# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_master_head.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/23 19:04:48 by ldevelle          #+#    #+#              #
#    Updated: 2019/05/07 12:32:24 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file=auto.h
path=$1$file

rm -rf $path

echo '#ifndef AUTO_H' > $path
echo '# define AUTO_H\n' >> $path

find includes/auto -type f | sed 's~includes/auto~# include "auto~g' | sed 's~\.h~\.h"~g' >> $path

echo '' >> $path
echo '#endif' >> $path

vim -c :Stdheader -c:wq $path
