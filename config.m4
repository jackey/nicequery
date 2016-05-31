PHP_ARG_ENABLE(nice_query, weather to enable nice_query support, [--enable-nice_query Enable nice_query support])

if test "$PHP_NICE_QUERY" == "yes"; then
	AC_DEFINE(HAVE_NICE_QUERY, 1 , [weather you have nice_query])
	PHP_NEW_EXTENSION(nice_query, nice_query.c slobel_darray.c , $ext_shared)
fi