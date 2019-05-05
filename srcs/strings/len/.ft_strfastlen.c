/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfastlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/12 17:52:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return the length of the null-terminated string STR.  Scan for
   the null terminator quickly by testing four bytes at a time.  */
size_t		ft_strfastlen(const char *str)
{
  const char				*char_ptr;
  const unsigned long int	*longword_ptr;
  unsigned long int			longword;
  unsigned long int			magic_bits;
  unsigned long int			himagic;
  unsigned long int			lomagic;

  /* Handle the first few characters by reading one character at a time.
     Do this until CHAR_PTR is aligned on a longword boundary.  */
  for (char_ptr = str; ((unsigned long int) char_ptr
                        & (sizeof (longword) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == '\0')
      return char_ptr - str;

  /* All these elucidatory comments refer to 4-byte longwords,
     but the theory applies equally well to 8-byte longwords.  */

  longword_ptr = (unsigned long int *) char_ptr;

  /* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
     the "holes."  Note that there is a hole just to the left of
     each byte, with an extra at the end:

     bits:  01111110 11111110 11111110 11111111
     bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD

     The 1-bits make sure that carries propagate to the next 0-bit.
     The 0-bits provide holes for carries to fall into.  */
  magic_bits = 0x7efefeffL;
  himagic = 0x80808080L;
  lomagic = 0x01010101L;
  if (sizeof (longword) > 4)
    {
      /* 64-bit version of the magic.  */
      /* Do the shift in two steps to avoid a warning if long has 32 bits.  */
      magic_bits = ((0x7efefefeL << 16) << 16) | 0xfefefeffL;
      himagic = ((himagic << 16) << 16) | himagic;
      lomagic = ((lomagic << 16) << 16) | lomagic;
    }
  if (sizeof (longword) > 8)
    abort ();

  /* Instead of the traditional loop which tests each character,
     we will test a longword at a time.  The tricky part is testing
     if *any of the four* bytes in the longword in question are zero.  */
  for (;;)
    {
      /* We tentatively exit the loop if adding MAGIC_BITS to
         LONGWORD fails to change any of the hole bits of LONGWORD.

         1) Is this safe?  Will it catch all the zero bytes?
         Suppose there is a byte with all zeros.  Any carry bits
         propagating from its left will fall into the hole at its
         least significant bit and stop.  Since there will be no
         carry from its most significant bit, the LSB of the
         byte to the left will be unchanged, and the zero will be
         detected.

         2) Is this worthwhile?  Will it ignore everything except
         zero bytes?  Suppose every byte of LONGWORD has a bit set
         somewhere.  There will be a carry into bit 8.  If bit 8
         is set, this will carry into bit 16.  If bit 8 is clear,
         one of bits 9-15 must be set, so there will be a carry
         into bit 16.  Similarly, there will be a carry into bit
         24.  If one of bits 24-30 is set, there will be a carry
         into bit 31, so all of the hole bits will be changed.

         The one misfire occurs when bits 24-30 are clear and bit
         31 is set; in this case, the hole at bit 31 is not
         changed.  If we had access to the processor carry flag,
         we could close this loophole by putting the fourth hole
         at bit 32!

         So it ignores everything except 128's, when they're aligned
         properly.  */

      longword = *longword_ptr++;

      if (
#if 0
          /* Add MAGIC_BITS to LONGWORD.  */
          (((longword + magic_bits)

            /* Set those bits that were unchanged by the addition.  */
            ^ ~longword)

           /* Look at only the hole bits.  If any of the hole bits
              are unchanged, most likely one of the bytes was a
              zero.  */
           & ~magic_bits)
#else
          ((longword - lomagic) & himagic)
#endif
          != 0)
        {
          /* Which of the bytes was the zero?  If none of them were, it was
             a misfire; continue the search.  */

          const char *cp = (const char *) (longword_ptr - 1);

          if (cp[0] == 0)
            return cp - str;
          if (cp[1] == 0)
            return cp - str + 1;
          if (cp[2] == 0)
            return cp - str + 2;
          if (cp[3] == 0)
            return cp - str + 3;
          if (sizeof (longword) > 4)
            {
              if (cp[4] == 0)
                return cp - str + 4;
              if (cp[5] == 0)
                return cp - str + 5;
              if (cp[6] == 0)
                return cp - str + 6;
              if (cp[7] == 0)
                return cp - str + 7;
            }
        }
    }
}










/*
** size_t    ft_strlen(const char *s)
** {
**     long long int    size;
**
**     size = 0;
**     if (!s || s[0] == '\0')
**         return (0);
**     while (s[size] != '\0')
**     {
**         if (s[size + 1] == '\0' || s[size + 2] == '\0')
**             return ((s[size + 1] == '\0') ? size + 1 : size + 2);
**         else if (s[size + 3] == '\0' || s[size + 4] == '\0')
**             return ((s[size + 3] == '\0') ? size + 3 : size + 4);
**         else if (s[size + 5] == '\0' || s[size + 6] == '\0')
**             return ((s[size + 5] == '\0') ? size + 5 : size + 6);
**         else if (s[size + 7] == '\0' || s[size + 8] == '\0')
**             return ((s[size + 7] == '\0') ? size + 7 : size + 8);
**         else if (s[size + 9] == '\0' || s[size + 10] == '\0')
**             return ((s[size + 9] == '\0') ? size + 9 : size + 10);
**         else if (s[size + 11] == '\0' || s[size + 12] == '\0')
**             return ((s[size + 11] == '\0') ? size + 11 : size + 12);
**         else if (s[size + 13] == '\0' || s[size + 14] == '\0')
**             return ((s[size + 13] == '\0') ? size + 13 : size + 14);
**         size += 15;
**     }
**     return (size);
** }
*/
