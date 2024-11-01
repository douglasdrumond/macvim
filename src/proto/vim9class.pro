/* vim9class.c */
int object_index_from_itf_index(class_T *itf, int is_method, int idx, class_T *cl);
int is_valid_builtin_obj_methodname(char_u *funcname);
ufunc_T *class_get_builtin_method(class_T *cl, class_builtin_T builtin_method, int *method_idx);
void ex_class(exarg_T *eap);
void enum_set_internal_obj_vars(class_T *en, object_T *enval);
type_T *oc_member_type(class_T *cl, int is_object, char_u *name, char_u *name_end, int *member_idx);
type_T *oc_member_type_by_idx(class_T *cl, int is_object, int member_idx);
void ex_enum(exarg_T *eap);
void typealias_unref(typealias_T *ta);
void ex_type(exarg_T *eap);
int class_object_index(char_u **arg, typval_T *rettv, evalarg_T *evalarg, int verbose);
ufunc_T *find_class_func(char_u **arg);
int class_member_idx(class_T *cl, char_u *name, size_t namelen);
ocmember_T *class_member_lookup(class_T *cl, char_u *name, size_t namelen, int *idx);
int class_method_idx(class_T *cl, char_u *name, size_t namelen);
ocmember_T *object_member_lookup(class_T *cl, char_u *name, size_t namelen, int *idx);
int object_method_idx(class_T *cl, char_u *name, size_t namelen);
ocmember_T *member_lookup(class_T *cl, vartype_T v_type, char_u *name, size_t namelen, int *idx);
ufunc_T *method_lookup(class_T *cl, vartype_T v_type, char_u *name, size_t namelen, int *idx);
int inside_class(cctx_T *cctx_arg, class_T *cl);
int oc_var_check_ro(class_T *cl, ocmember_T *m);
void obj_lock_const_vars(object_T *obj);
void copy_object(typval_T *from, typval_T *to);
void copy_class(typval_T *from, typval_T *to);
void class_unref(class_T *cl);
int class_free_nonref(int copyID);
int set_ref_in_classes(int copyID);
void object_created(object_T *obj);
void object_unref(object_T *obj);
int object_free_nonref(int copyID);
void object_free_items(int copyID);
void emsg_var_cl_define(char *msg, char_u *name, size_t len, class_T *cl);
void method_not_found_msg(class_T *cl, vartype_T v_type, char_u *name, size_t len);
void member_not_found_msg(class_T *cl, vartype_T v_type, char_u *name, size_t len);
void defcompile_class(class_T *cl);
void defcompile_classes_in_script(void);
int is_class_name(char_u *name, typval_T *rettv);
void protected_method_access_errmsg(char_u *method_name);
int object_empty(object_T *obj);
int object_len(object_T *obj);
int object_equal(object_T *o1, object_T *o2, int ic);
char_u *object2string(object_T *obj, char_u *numbuf, int copyID, int echo_style, int restore_copyID, int composite_val);
int class_instance_of(class_T *cl, class_T *other_cl);
void f_instanceof(typval_T *argvars, typval_T *rettv);
/* vim: set ft=c : */
