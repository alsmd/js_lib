#include <js_lib.h>

char	*store_by_type(t_json_obj *obj, char *json)
{
	if (*json == '"')
	{
		obj->type = JSON_STRING;
		obj->string_value = js_new_string(json);
		json++;
		while (*json != '"')
			json++;
		json++;
	}
	if (*json == '[')
		json = js_new_array(json, obj);
	else if (*json == '{')
	{
		obj->obj_value = calloc(1, sizeof(t_json_obj));
		json = js_new_obj(json, obj->obj_value);

	}
	else if (!strncmp(json, "true", 4))
	{
		obj->type = JSON_BOOL;
		json += 4;
		obj->int_value = 1;
	}
	else if (!strncmp(json, "false", 5))
	{
		obj->type = JSON_BOOL;
		json += 5;
		obj->int_value = 0;
	}
	else if (!strncmp(json, "null", 4))
	{
		obj->type = JSON_NULL;
		json += 4;
	}
	else if (is_number(*json))
	{
		obj->type = JSON_INTEGER;
		obj->int_value = atoi(json);
		while (is_number(*json))
			json++;
	}
	return (json);
}

/*
	@brief		Create a new object type and store in t_json_obj *obj
	@param		json  (json string pointing to a json's key: "name": "flavio").
				It has to point to the double quoutes of the key
*/
char	*js_new_obj_attr(char *json, t_json_obj *obj)
{
	json++;
	obj->key = strndup(json, strlen_var(json, '"'));
	while (*json != ':')
		json++;
	json++;
	json = jump_whitespace(json);
	json = store_by_type(obj, json);
	return (json);
}

/*
	@brief	
	@param		json  (json string pointing to the value of the array).
				
*/
char	*js_new_array_attr(char *json, t_json_obj *obj)
{
	json = store_by_type(obj, json);
	return (json);
}