PAT += 	srcs/big/ft_printf/ft_printf.c \
	srcs/big/ft_printf/check_arg.c \
	srcs/big/ft_printf/check_arg2.c \
	srcs/big/ft_printf/bonus_gestion.c \
	srcs/big/ft_printf/bonus_color.c \
	srcs/big/ft_printf/ajust_flags.c \
	srcs/inout/read/ft_gnl.c \
	srcs/inout/read/ft_get_next_line.c \
	srcs/inout/converters/ft_u_nb_to_a.c \
	srcs/inout/converters/ft_u_nb_len.c \
	srcs/inout/converters/ft_patoi.c \
	srcs/inout/converters/ft_nb_to_a.c \
	srcs/inout/converters/ft_nb_len.c \
	srcs/inout/converters/ft_nb_char_to_int.c \
	srcs/inout/converters/ft_itoa.c \
	srcs/inout/converters/ft_is_str_bigger_than_int.c \
	srcs/inout/converters/ft_intlen.c \
	srcs/inout/converters/ft_atoi.c \
	srcs/greg/gnl.c \
	srcs/greg/ft_strtrim_free.c \
	srcs/greg/ft_strstartwith.c \
	srcs/greg/ft_strndup.c \
	srcs/greg/ft_strendswith.c \
	srcs/greg/ft_strappend.c \
	srcs/files/ft_read_file.c \
	srcs/files/ft_get_tab_from_file.c \
	srcs/files/ft_get_size_file.c \
	srcs/files/ft_get_file.c \
	srcs/files/ft_create_new_file.c \
	srcs/files/ft_add_to_file.c \
	srcs/data_base/ft_unstore_htable.c \
	srcs/data_base/ft_store_htable.c \
	srcs/data_base/ft_htable_mem.c \
	srcs/data_base/ft_hfunc.c \
	srcs/data_base/ft_get_file_in_htable.c \
	srcs/data_base/ft_access_htable.c \
	srcs/big/time/time_exe.c \
	srcs/big/time/print_time.c \
	srcs/big/time/extra_func.c \
	srcs/big/ft_printf/type_unsigned_integer.c \
	srcs/big/ft_printf/type_string.c \
	srcs/big/ft_printf/type_pointer.c \
	srcs/big/ft_printf/type_integer.c \
	srcs/big/ft_printf/type_float.c \
	srcs/big/ft_printf/type_float2.c \
	srcs/big/ft_printf/type_character.c \
	srcs/big/ft_printf/type_binary.c \
	srcs/big/ft_printf/tools_flag.c \
	srcs/big/ft_printf/tools_flag2.c \
	srcs/big/ft_printf/parsing.c \
	srcs/big/ft_printf/output.c \
	srcs/big/ft_printf/init.c \
	srcs/big/ft_printf/get_str_str.c \
	srcs/big/ft_printf/get_str_int.c \
	srcs/big/ft_printf/get_str_float.c \
	srcs/big/ft_printf/get_str_char.c \
	srcs/big/ft_printf/get_printf.c \
	srcs/mem/transform/ft_bzero.c \
	srcs/mem/search/ft_memcmp.c \
	srcs/mem/search/ft_memchr.c \
	srcs/mem/nalloc/ft_switch_garbage.c \
	srcs/mem/nalloc/ft_nalloc.c \
	srcs/mem/nalloc/ft_malloco.c \
	srcs/mem/nalloc/ft_garbage_collector.c \
	srcs/mem/nalloc/ft_cnalloc.c \
	srcs/mem/nalloc/ft_clean_garbage.c \
	srcs/mem/nalloc/ft_burn_garbage.c \
	srcs/mem/malloc/ft_strnew.c \
	srcs/mem/malloc/ft_memalloc.c \
	srcs/mem/del/ft_strdel_multi.c \
	srcs/mem/del/ft_memdel.c \
	srcs/mem/del/ft_free_with_nalloc.c \
	srcs/mem/del/ft_del.c \
	srcs/mem/copy/ft_memmove.c \
	srcs/mem/copy/ft_memcpy.c \
	srcs/mem/copy/ft_memccpy.c \
	srcs/maths/suites/ft_nprime.c \
	srcs/maths/suites/ft_fibonacci.c \
	srcs/maths/sort/ft_squick_sort.c \
	srcs/maths/sort/ft_quick_sort.c \
	srcs/maths/round/ft_round_upper.c \
	srcs/maths/round/ft_round.c \
	srcs/maths/round/ft_rfpart.c \
	srcs/maths/round/ft_ipart.c \
	srcs/maths/round/ft_fpart.c \
	srcs/maths/random/seed/ft_seed_time.c \
	srcs/maths/random/seed/ft_seed_string.c \
	srcs/maths/random/seed/ft_seed_gnl.c \
	srcs/maths/random/seed/ft_seed_adress.c \
	srcs/maths/random/ft_simple_random.c \
	srcs/maths/random/ft_random.c \
	srcs/maths/random/ft_rand.c \
	srcs/maths/operators/ft_sum_to_nb.c \
	srcs/maths/operators/ft_power.c \
	srcs/maths/operators/ft_nb_in_range.c \
	srcs/maths/operators/ft_fsqrt.c \
	srcs/maths/operators/ft_factorial.c \
	srcs/maths/operators/ft_abs.c \
	srcs/inout/write/string/ft_putstr.c \
	srcs/inout/write/string/ft_putnstr.c \
	srcs/inout/write/string/ft_putendl.c \
	srcs/inout/write/spacing/ft_puttab_len.c \
	srcs/inout/write/spacing/ft_puttab.c \
	srcs/inout/write/return/ft_putstr_rnull.c \
	srcs/inout/write/return/ft_putstr_r0_fd.c \
	srcs/inout/write/return/ft_putstr_r0.c \
	srcs/inout/write/nb/ft_putnbr.c \
	srcs/inout/write/nb/ft_putbnbr_str.c \
	srcs/inout/write/fd/ft_putstr_fd.c \
	srcs/inout/write/fd/ft_putnbr_fd.c \
	srcs/inout/write/fd/ft_putendl_fd.c \
	srcs/inout/write/fd/ft_putchar_fd.c \
	srcs/inout/write/char/ft_putchar.c \
	srcs/structures/tab/len/ft_tab_lendir.c \
	srcs/structures/tab/ft_is/ft_tabloop_itis.c \
	srcs/structures/tab/dir/ft_tab_dir_reverse.c \
	srcs/structures/tab/dir/ft_tab_dir_rclock.c \
	srcs/structures/tab/dir/ft_tab_dir_nclock.c \
	srcs/structures/tab/dir/ft_tab_dir_clock.c \
	srcs/structures/tab/del/ft_tab_delete_row_len.c \
	srcs/structures/tab/del/ft_tab_delete_row.c \
	srcs/structures/tab/create/ft_tab_square_it.c \
	srcs/structures/tab/create/ft_tabnew_rectangle.c \
	srcs/structures/tab/create/ft_tabnew_ptr.c \
	srcs/structures/tab/create/ft_tabnew_dir.c \
	srcs/structures/tab/connect/ft_tabloop_it.c \
	srcs/structures/tab/connect/ft_tab_cutone.c \
	srcs/structures/tab/connect/ft_tab_cut_loop.c \
	srcs/structures/tab/connect/ft_tab_connect_structs.c \
	srcs/structures/tab/connect/ft_tab_connect_dir.c \
	srcs/structures/tab/connect/ft_tabadd_start.c \
	srcs/structures/tab/connect/ft_tabadd_here.c \
	srcs/structures/tab/connect/ft_tabadd_end.c \
	srcs/structures/tab/connect/ft_tabadd.c \
	srcs/structures/list/transform/ft_lstmap.c \
	srcs/structures/list/transform/ft_lstiter.c \
	srcs/structures/list/move/ft_lst_reach_end.c \
	srcs/structures/list/move/ft_lstfind_th.c \
	srcs/structures/list/len/ft_lst_count.c \
	srcs/structures/list/del/ft_lst_free.c \
	srcs/structures/list/del/ft_lstdelone.c \
	srcs/structures/list/del/ft_lstdel.c \
	srcs/structures/list/create/ft_lstnew_ptr.c \
	srcs/structures/list/create/ft_lstnew.c \
	srcs/structures/list/connect/ft_lstcutone.c \
	srcs/structures/list/connect/ft_lstadd_start.c \
	srcs/structures/list/connect/ft_lstadd_here.c \
	srcs/structures/list/connect/ft_lstadd_end.c \
	srcs/structures/list/connect/ft_lstadd.c \
	srcs/strings/transform/ft_strmapi.c \
	srcs/strings/transform/ft_strmap.c \
	srcs/strings/transform/ft_striteri.c \
	srcs/strings/transform/ft_striter.c \
	srcs/strings/transform/ft_strclr.c \
	srcs/strings/search/ft_strstr.c \
	srcs/strings/search/ft_strrchr.c \
	srcs/strings/search/ft_strnstr.c \
	srcs/strings/search/ft_strchr.c \
	srcs/strings/search/ft_pstrnstr.c \
	srcs/strings/search/ft_nmatch.c \
	srcs/strings/search/ft_match.c \
	srcs/strings/search/ft_char_srch.c \
	srcs/strings/len/ft_strnlen.c \
	srcs/strings/len/ft_strlen.c \
	srcs/strings/ft_is/ft_toupper.c \
	srcs/strings/ft_is/ft_tolower.c \
	srcs/strings/ft_is/ft_isupper.c \
	srcs/strings/ft_is/ft_isprint.c \
	srcs/strings/ft_is/ft_islower.c \
	srcs/strings/ft_is/ft_isdigit.c \
	srcs/strings/ft_is/ft_isascii.c \
	srcs/strings/ft_is/ft_isalpha.c \
	srcs/strings/ft_is/ft_isalnum.c \
	srcs/strings/duplicate/ft_strtrim.c \
	srcs/strings/duplicate/ft_strsub.c \
	srcs/strings/duplicate/ft_strsplit.c \
	srcs/strings/duplicate/ft_strrealloc.c \
	srcs/strings/duplicate/ft_strjoin_multi.c \
	srcs/strings/duplicate/ft_strjoin.c \
	srcs/strings/duplicate/ft_strdup.c \
	srcs/strings/copy/ft_strncpy.c \
	srcs/strings/copy/ft_strncat.c \
	srcs/strings/copy/ft_strlcat.c \
	srcs/strings/copy/ft_strcpy.c \
	srcs/strings/copy/ft_strcat.c \
	srcs/strings/compare/ft_strnequ.c \
	srcs/strings/compare/ft_strncmp.c \
	srcs/strings/compare/ft_strequ.c \
	srcs/strings/compare/ft_strcmp.c \
	srcs/mem/transform/ft_swap.c \
	srcs/mem/transform/ft_memset.c \
	srcs/vector/vct_strjoin.c \
	srcs/vector/vct_replace_char.c \
	srcs/vector/vct_replace_char_at.c \
	srcs/vector/vct_pushstr.c \
	srcs/vector/vct_pop_from.c \
	srcs/vector/vct_pop.c \
	srcs/vector/vct_newstr.c \
	srcs/vector/vct_new.c \
	srcs/vector/vct_len.c \
	srcs/vector/vct_joinfree.c \
	srcs/vector/vct_join.c \
	srcs/vector/vct_increase_scale.c \
	srcs/vector/vct_getstr.c \
	srcs/vector/vct_getchar_at.c \
	srcs/vector/vct_fill_before.c \
	srcs/vector/vct_fill_after.c \
	srcs/vector/vct_dup.c \
	srcs/vector/vct_del.c \
	srcs/vector/vct_chr_str.c \
	srcs/vector/vct_chr.c \
	srcs/vector/vct_cat.c \
	srcs/vector/vct_bzero.c \
	srcs/vector/vct_addstr_at.c \
	srcs/vector/vct_addchar.c \
	srcs/vector/vct_addchar_at.c \
	srcs/terminal/other/ft_wait_pls.c \
	srcs/terminal/other/ft_progress.c \
	srcs/terminal/other/ft_press_any_key.c \
	srcs/terminal/cursor/ft_place_cursor.c \
	srcs/terminal/color/ft_str_rgbcolor.c \
	srcs/terminal/color/ft_rgb_color.c \
	srcs/terminal/color/ft_rgb_bcolor.c \
	srcs/terminal/color/ft_putstr_color.c \
	srcs/terminal/color/ft_print_address_color.c \
	srcs/structures/tab/transform/ft_tabiter.c \
	srcs/structures/tab/print/ft_tab_print_one_elmnt.c \
	srcs/structures/tab/print/ft_tab_print_dir.c \
	srcs/structures/tab/move/ft_tab_reach_end.c \
	srcs/structures/tab/move/ft_tab_dirth.c \
	srcs/structures/tab/move/ft_tab_access.c \
	srcs/structures/tab/len/ft_tabloop_lendir.c \
	srcs/maths/operators/ft_fabs.c \
	srcs/structures/rbt/insert/tree_insert_repair.c \
	srcs/structures/rbt/print/tree_str.c \
	srcs/structures/rbt/print/tree_simple_print.c \
	srcs/structures/rbt/print/print_node_info.c \
	srcs/structures/rbt/tree_free.c \
	srcs/mem/del/ft_strdel.c \
	srcs/structures/rbt/tree_recoloring.c \
	srcs/structures/rbt/tree_new_node.c \
	srcs/structures/rbt/tree_genealogy.c \
	srcs/structures/rbt/print/tree_print.c \
	srcs/structures/rbt/map/tree_inrorder.c \
	srcs/structures/rbt/map/tree_inorder.c \
	srcs/structures/rbt/insert/tree_insert_recurse.c \
	srcs/structures/rbt/insert/tree_insert.c \
	srcs/structures/rbt/insert/tree_insert_case.c \
	srcs/structures/rbt/remove/tree_remove.c \
	srcs/structures/rbt/remove/tree_remove_case_1.c \
	srcs/structures/rbt/remove/tree_remove_case_2.c \
	srcs/structures/rbt/tree_rotations.c \
	srcs/structures/list/move/ft_lstcut.c \
	srcs/big/parse/parse_mem.c \
	srcs/big/parse/parse_print.c \
	srcs/big/parse/parse_add.c \
	srcs/big/parse/parse_new.c \
	srcs/big/parse/parse_get.c \
	srcs/big/parse/parse_free.c \
	srcs/big/parse/parse_args_save.c \
	srcs/big/parse/parse_usage.c \
	srcs/big/parse/parse_args.c 
