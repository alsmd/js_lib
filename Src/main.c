#include <js_lib.h>

/***************
 * 
 * 	CREATE NODES
 * 
****************/
t_json_obj	*js_convert_to_object(char *j)
{
	char		*json;
	t_json_obj	*obj;

	json = strdup(j);
	obj = calloc(1, sizeof(t_json_obj));
	js_new_obj(json, obj);
	free(json);
	return (obj);
}
/***************
 * 
 * 	CREATE NODES END
 * 
****************/

void	printf_array_items(t_json_obj *item)
{
	if (item->type == JSON_STRING)
		printf("%s\n", item->string_value);
	if (item->type == JSON_INTEGER ||item->type == JSON_BOOL)
		printf("%d\n", item->int_value);
}


int	main(void)
{
	t_json_obj	obj;
	
	js_new_array("[1, 2, 3, \"name\", 5, 6]", &obj);


	js_foreach(&obj, printf_array_items);
	return (0);
}
