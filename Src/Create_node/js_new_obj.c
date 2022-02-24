#include <js_lib.h>

/*
	@brief		Receive a string json and convert to a t_json_obj, you can use search function in this obj to get the attributes
	@param		json (json string that will be the base for the new t_json_obj, it has to point to "[")
	@param		obj (a t_json_obj where the new obj will be store.)
	@return		Returns a (char *) pointing to where this object ends inside the string json passed as parameter
*/
char	*js_new_obj(char *json, t_json_obj *obj)
{
	t_json_obj	*begin;

	bzero(obj, sizeof(obj));
	obj->type = JSON_OBJ;
	begin = obj;
	json += 1;
	while (*json != '}')
	{
		json = jump_whitespace(json);
		if (*json == '}')
			break ;
		if (*json == ',')
		{
			json++;
			json = jump_whitespace(json);
			begin->next = calloc(1, sizeof(t_json_obj));
			begin = begin->next;
			json = js_new_obj_attr(json, begin);
		}
		else
			json = js_new_obj_attr(json, begin);
	}
	json++;
	return (json);
}