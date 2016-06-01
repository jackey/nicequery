PHP_ARG_ENABLE(nicequery, whether to enable nicequery, 
[ --enable-extnicequery             Enable extnicequery])

if test "$PHP_EXTNICEQUERY" != "no"; then
  PHP_NEW_EXTENSION(extnicequery, nicequery.c, $ext_shared)
fi

