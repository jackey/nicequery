PHP_ARG_ENABLE(nicequery, whether to enable nicequery, 
[ --enable-nicequery             Enable nicequery])

if test "$PHP_NICEQUERY" != "no"; then
  PHP_NEW_EXTENSION(nicequery, nicequery.c, $ext_shared)
fi

