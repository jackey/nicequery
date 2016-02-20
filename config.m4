PHP_ARG_ENABLE(nice_query, whether to enable nice query support, 
	[--enable-nice_query              Enbale Nice Query support])

if test $PHP_NICE_QUERY = "yes"; then 
	AC_DEFINE(HAVE_NICE_QUERY, 1, [Whether to enbale nice query support])
	PHP_NEW_EXNTESION(nice_query, nice_query.c, $ext_shared)
fi