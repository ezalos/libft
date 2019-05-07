find srcs/ -type f -exec cat {} \+ |
grep -A1 -e ft_ -e nalloc -e get_next_line |
grep -A1 -e ^int -e ^char -e ^void -e ^size_t -e ^t_list -e ^intmax_t -e ^uintmax_t -e ^"t_tab" -e "\.\.\." |
grep -v -e ":+:" -e "+:+" -e "\*\* " -e "\*\*\$" -e "\$\$" -e "{" -e "}" -e "/\\*" -e "\\*/" -e "--" -e static -e while -e else -e "\*\\\\" -e if -e ";" -e "#include " -e "=" -e "->"
