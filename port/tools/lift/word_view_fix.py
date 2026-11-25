#!/usr/bin/env python3
"""Medias palabras dentro de una palabra que el resto del juego lee entera.

El registro de clase guarda en +0x20 una palabra con flags (mitad alta) y contador de instancias (mitad baja), y unas
unidades la leen con lwz y otras con lhz en +0x22. Los datos del DOL se convierten como palabra, así que en un anfitrión
little-endian esa mitad baja está en +0x20. Sin esto, el contador suma sobre los flags y borra el bit de inicializada.
"""
import re

# Hay más de 60 unidades con su vista del registro: acolchado de 34 B y contador, con o sin campos detrás.
PATTERN = re.compile(r'(?:unsigned )?char (\w+)\[(?:0x22|34)\];(\s*)(?:unsigned short|u16|w3d_u16) (\w+);')


# Añadir un carácter a una cadena: en PPC el short c << 8 son los bytes {c, 0}; en little-endian esos bytes son el propio c.
CHAR_AS_SHORT = 'sp8 = arg1 << 8;\n    fn_8020BF2C('


TYPE_ID_THEN_COUNT = 'unsigned short :6; unsigned short type_id:10;\n    unsigned short count;'
EXPR_COUNT = '(&(*new_var))) + 0x22)'


# El original no comprueba si la clave existe y lee la pila sin iniciar: en PPC ese valor era inofensivo, aquí no.
UNSET_TEXT = '        Ptr32<const char> stored;\n        Ptr32<const char> first = d24i_name_8039bd80;'


# La copia a ARAM del port termina al momento y llama al aviso dentro de la petición: el estado tiene que estar puesto antes.
ARAM_POST = re.compile(r'( w3d_request_hardware_post\(r->backend[^;]*;)\n( w3d_active_request=r;r->state=[45];)')


# Entrada de recurso: la palabra en +0x18 es un entero del anfitrión (bit 0x8000), así que el byte PPC +0x18 está en +0x1b y +0x19 en +0x1a.
VIRTUAL_REF = re.compile(r'Ptr32<((?:const )?[\w:]+) *&\(Ptr32<')
PLACE_PTR = re.compile(r'new *\(([^;]*?)\) *((?:const )?[A-Za-z_][A-Za-z_0-9:<>]*) *\* *\(([^;]*)\);')
NEW_ARRAY = re.compile(r'\bnew\s+((?:const\s+)?[A-Za-z_][\w:]*(?:\s*<[^;()\[\]]*>)?(?:\s*\*)*)\s*\[([^\]\n]+)\]')
DELETE_ARRAY = re.compile(r'(?<!operator)(^|[;{}\s])delete\s*\[\s*\]\s*([^;\n]+);', re.M)
GRID_LINK = re.compile(r'\bcorner\[(\d*[13579])\]')
LOST_THIS = re.compile(r'M2C_FIELD\(\*([a-zA-Z_0-9]+), Ptr32<([A-Za-z_0-9 ]+) \(void\)> \*, (0x[0-9A-Fa-f]+)\)\(\)')
RECORD_BYTES = {
    'd28e_add_draw_block_801aa15c.cpp': [('    b->next = self->a228;', '    { unsigned k = self->a228.v; b->next.v = k << 16 | k >> 16; } /* clave de orden: dos u16 en +228 y +230, la primera en la mitad alta en PPC */')],
    'd41e_heap_config_802092c8.cpp': [('    w3d_d30e_heap_init_8020941c(self, size);\n', '    size *= W3D_ARENA_SCALE;\n    w3d_d30e_heap_init_8020941c(self, size);\n'), ('extern "C" int w3d_d41e_heap_config_802092c8(Ptr32<Heap> self)', '/* Las arenas se dimensionaron para los 24 MB de GameCube. Con terreno, MField y XContainer se llenan en la carga; aquí sobra memoria. */\nenum { W3D_ARENA_SCALE = 3 };\nextern "C" int w3d_d41e_heap_config_802092c8(Ptr32<Heap> self)')],
    'tterra_b26_visit_node_801aab74.cpp': [(' case 1:channel=owner->channel[1];break;\n', ' case 1:channel=owner->channel[1];break;\n default:channel=owner->channel[0];break; /* en PPC queda el r27 del llamante: no puede indexar listas */\n')],
    # Pendiente de causa: hay objetos con 0x02 en el byte alto de la etiqueta y id 0. Sin esto vaciarían la ranura 0, que usa cualquier clave sin registrar.
    'actor_registry_remove.cpp': [('    unsigned short index = (unsigned short)(node->unknown_04 >> 8);\n', '    unsigned short index = (unsigned short)(node->unknown_04 >> 8);\n    if (index == 0) return;\n')],
    # Bytes de orden del contenedor de escena: se escriben en +0x1b y +0x1a (ver d41x_scene_bins); deciden la lista de dibujo.
    # Puntero a método guardado como dos enteros, tanto desde los datos como desde literales en la pila: las mitades se sacan de la palabra.
    's3_message_callbacks.cpp': [('short index=((Ptr32<short>)&callback->member)[1];', 'short index=(short)callback->member.encoded;'),
        ('((Ptr32<short>)&callback->member)[2]', '(short)(callback->member.target>>16)'),
        ('((Ptr32<short>)&callback->member)[0]', '(short)(callback->member.encoded>>16)')],
    # Contador de generadores de textura: PPC lee el byte bajo de la palabra en +0xd8, que aquí está en +0xd8 y no en +0xdb.
    's20_adjust_p.cpp': [('*(Ptr32<unsigned char>)(base + 219)', '*(Ptr32<unsigned char>)(base + 216)')],
    's20_adjust_q.cpp': [('*(Ptr32<unsigned char>)(base + 219)', '*(Ptr32<unsigned char>)(base + 216)')],
    's20_adjust_t.cpp': [('*(Ptr32<unsigned char>)(base + 219)', '*(Ptr32<unsigned char>)(base + 216)')],
    's20_adjust_j.cpp': [('*(Ptr32<unsigned char>)(base + 219)', '*(Ptr32<unsigned char>)(base + 216)')],
    # La lectura DVD ya convierte la cabecera DSP por palabras: la frecuencia, que PPC lee en +0xa, está en +8.
    'd30e_voice_update_801e6054.cpp': [('struct Info { char x0[4]; unsigned rate; char x8[2]; unsigned short kind;', 'struct Info { char x0[4]; unsigned rate; unsigned short kind; char x8[2];')],
    # Sentencia sin efecto en PPC, solo para igualar bytes: aquí desreferencia nulo.
    's21_cp_801e6bbc.cpp': [('  self->held->methods->release += 0;\n', '')],
    'd30e_load_tga_resource_801b44f8.cpp': [('Ptr32<void> data;\n    n->v40(&data);\n    hr = c.p->v20(data, st.size, 0);', 'Ptr32<void> data[3];\n    n->v40(&data[0]);\n    hr = c.p->v20(data[0], st.size, 0);')],
    # Escritores de tipo y grupo: al escribirse en +0x18/+0x19 el recurso sale con tipo 0 y se crea el objeto equivocado.
    'cx16b_descriptor_apply_80187158.cpp': [('FIELD(self,unsigned char,24)', 'FIELD(self,unsigned char,27)'), ('FIELD(self,unsigned char,25)', 'FIELD(self,unsigned char,26)')],
    'cx16b_descriptor_defaults_8018a218.cpp': [('FIELD(self,unsigned char,24)', 'FIELD(self,unsigned char,27)'), ('FIELD(self,unsigned char,25)', 'FIELD(self,unsigned char,26)')],
    's9beam_80187208.cpp': [('M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(temp_r3, u8 *, 0x19);', 'M2C_FIELD(arg0, u8 *, 0x1A) = (u8) M2C_FIELD(temp_r3, u8 *, 0x1A);')],
    's9beam_8018a2c4.cpp': [('M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(temp_r3, u8 *, 0x19);', 'M2C_FIELD(arg0, u8 *, 0x1A) = (u8) M2C_FIELD(temp_r3, u8 *, 0x1A);')],
    's9resources_8015caec.cpp': [('FIELD(value,char,25)=', 'FIELD(value,char,26)='), ('FIELD(target,char,24)=', 'FIELD(target,char,27)=')],
    'f14a_load_game_data_80289eec.cpp': [('Ptr32<void> data; unsigned unobservedStorage; };', 'Ptr32<void> data; unsigned unobservedStorage; unsigned w3d_capacity; };')],
    # Etiqueta del objeto: los bytes de tipo y flags son la parte baja de la palabra.
    'g2b_read_schema_v3_801ea2d8.cpp': [('struct Header {unsigned unknown;unsigned short unknown4;unsigned char kind,flags;}', 'struct Header {unsigned unknown;unsigned char flags,kind;unsigned short unknown4;}')],
    'g2b_write_schema_801ea18c.cpp': [('struct Header {unsigned unknown;unsigned short unknown4;unsigned char kind,flags;}', 'struct Header {unsigned unknown;unsigned char flags,kind;unsigned short unknown4;}')],
    'gen_8017eaa0.cpp': [('unsigned char unknown_00[0x19];\n    unsigned char value;\n} W3dFieldU8At19;', 'unsigned char unknown_00[0x1a];\n    unsigned char value;\n} W3dFieldU8At19;')],
    'auto_801656bc.cpp': [('M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(temp_r3, u8 *, 0x19);', 'M2C_FIELD(arg0, u8 *, 0x1A) = (u8) M2C_FIELD(temp_r3, u8 *, 0x1A);')],
    'd10a_acquire_slot_8017180c_v5.cpp': [('unsigned char unknown[24]; unsigned char kind, default_group;', 'unsigned char unknown[26]; unsigned char default_group, kind;')],
    'd24j_acquire_slot_8017f6ec.cpp': [('unsigned char unknown[24]; unsigned char kind, default_group; unsigned char u26[10];', 'unsigned char unknown[26]; unsigned char default_group, kind; unsigned char u26[8];')],
    'h2a_take_pool_item_callback_8017467c.cpp': [('unsigned char unknown0[24];unsigned char type,defaultMode;unsigned char unknown26[10];', 'unsigned char unknown0[26];unsigned char defaultMode,type;unsigned char unknown26[8];')],
    's9acquire_80182a24.cpp': [('FIELD(source, unsigned char, 25)', 'FIELD(source, unsigned char, 26)'), ('FIELD(source, unsigned char,24)', 'FIELD(source, unsigned char,27)')],
    's20_small_an.cpp': [('*(Ptr32<unsigned char>)(self + 24), lbl_803a820c', '*(Ptr32<unsigned char>)(self + 27), lbl_803a820c')],
    's20_small_af.cpp': [('sink, self + 24, lbl_803a820c', 'sink, self + 27, lbl_803a820c')],
    'd26h_lunar_sky_setup_800a4534.cpp': [('unsigned short initial = (unsigned char)world.text[0] << 8;', 'unsigned short initial = (unsigned char)world.text[0];')],
    's20_ctor_e.cpp': [('    bits->top = 0;\n    bits->first = 0;\n    bits->second = 0;\n', '    *(Ptr32<unsigned int>)(self + 28) &= 0x1ffff;\n    *(Ptr32<unsigned char>)(self + 26) = 0;\n    *(Ptr32<unsigned char>)(self + 27) = 0;\n')],
    'd32s_anim_load_801953e8.cpp': [('struct Info { char u[4]; unsigned char flags; char w3d_tag_rest[3]; };', 'struct Info { char u[6]; char w3d_kind; unsigned char flags; };')],
    'd32s_anim_bind_80195838.cpp': [('struct Info { char u[4]; unsigned char flags; char w3d_tag_rest[3]; };', 'struct Info { char u[6]; char w3d_kind; unsigned char flags; };')],
    'd40n_lua_property_access_8019eed4.cpp': [('struct Info { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; int kind; };', 'struct Info { char p0[6]; char w3d_kind; unsigned char flags; int kind; };')],
    's21_ah_801eb0b0.cpp': [('struct S21First { char pad[4]; unsigned char flags; char w3d_tag_rest[3]; };', 'struct S21First { char pad[6]; char w3d_kind; unsigned char flags; };')],
    # El llamador en C++ ya destruye el argumento por valor; GCC 2.95 lo hacía en la llamada.
    'autof_8004def0.cpp': [('block_4:\n    fn_8020C5C4(arg1);\n    fn_80341588(arg1);\n    return;\n}\n\nextern M2C_UNK lbl_8040DB38[];', 'block_4:\n    return;\n}\n\nextern M2C_UNK lbl_8040DB38[];')],
    'autof_800aa374.cpp': [('w3d_auto_800bc350(s32 arg0, s32 arg1) {\n    fn_8020C5C4(arg1);\n    fn_80341588(w3d::G(arg1));\n', 'w3d_auto_800bc350(s32 arg0, s32 arg1) {\n')],
    's11perm_802c7a0c.cpp': [('fn_802C7894(w3d::G(arg0), arg2, 1); fn_8020C5C4(arg1); } while (0);\n  fn_80341588(arg1);\n', 'fn_802C7894(w3d::G(arg0), arg2, 1); } while (0);\n')],
    # La malla comprimida a ARAM es solo para ahorrar memoria de la GameCube; aquí se queda en memoria tal cual.
    'd24j_compile_mesh_data_8017fe2c.cpp': [('    if (!(m->state & 32)) return 0;\n    compile(m);\n    return 0;\n', '    return 0;\n')],
    'd32i_strip_emit_triangles_8010aeb0.cpp': [('((Ptr32<unsigned char>)p)[3]', '((Ptr32<unsigned char>)p)[0]'), ('verts + x * 72 + y * 1296;', 'verts + x * 72 + y * 1296 + 2; /* vínculo B: mitad alta (PPC +0, anfitrión +2) */')],
    'k4a_entry_property_value_800fd388.cpp': [('K4aPropValue k4a_entry_property_value_800fd388(unsigned int slot)\n{\n    K4aPropValue v;\n', '/* En PPC el resultado va a un puntero oculto en r3, y así lo llaman todos. */\nPtr32<K4aPropValue> k4a_entry_property_value_800fd388(Ptr32<K4aPropValue> out, unsigned int slot)\n{\n'), ('    s8_indexed_property_800fd3e4(&v, entry->index);\n    return v;\n', '    s8_indexed_property_800fd3e4(out, entry->index);\n    return out;\n')],
    'd31c_radar_update_800feb48.cpp': [('extern "C" Colour colour_800fd388(...);', 'extern "C" Ptr32<Colour> colour_800fd388(Ptr32<Colour>, unsigned);'), ('colours_80189760(mesh)[i] = colour_800fd388(i);', 'Colour w3d_c; colour_800fd388(&w3d_c, i); colours_80189760(mesh)[i] = w3d_c;')],
    'k4a_owner_apply_property_8003d0a0.cpp': [('extern "C" K4aPropValue FUN_800fd388(...);', 'extern "C" Ptr32<K4aPropValue> FUN_800fd388(Ptr32<K4aPropValue>, unsigned);'), ('K4aPropValue value = FUN_800fd388(index);', 'K4aPropValue value; FUN_800fd388(&value, index);')],
    'd30j_load_geometry_block_8017ffbc.cpp': [('  if ((self->flags & 32) && self->loaded <= 0) {\n', '  /* Sin compresión a ARAM (ver d24j_compile_mesh_data) no hay bloque que leer. */\n  if ((self->flags & 32) && self->loaded <= 0 && self->block.size) {\n')],
    'cx16b_mesh_count_release_8017f818.cpp': [('    if(self->flags&32)fn_801801b0(self);\n', '')],
    # Referencias por valor: GCC 2.95 las destruye en la llamada; el llamador en C++ ya lo hace.
    'genparamc_8002f6dc.cpp': [('= *source;\n    if (*source)\n        VCALL(*source, 16);\n', '= *source;\n')],
    # s1_airstrike_cursor_verified.cpp (0x8004e2a4) sí suelta: sus dos llamadores no tienen destructor. Ver F12.
    'g_global_light.cpp': [('    if (*attachment)\n        (*attachment)->vtbl->release(*attachment);\n', '')],
    's20_small_am.cpp': [('    held = *holder;\n    if (held != 0)\n        ((S20Call0)held->vtable[4])(held);\n', '')],
    's2_trigger_components_r3.cpp': [('    if(*source) ((Ptr32<void (Ptr32<Object>)>)(*source)->vtable[4])(*source);\n', '')],
    'cx16b_reader_bind_801dafbc.cpp': [('    if(consumed)((Ptr32<void (Ptr32<Cx16bReadable>)>)consumed->vtable[4])(consumed);\n', '')],
    's11_receiver_8026d9a0.cpp': [('    if (*incoming) (*incoming)->vtable->release(*incoming);\n', '')],
    'cx13b_changed_interface_assign_802bdc88.cpp': [('changed_802bdd24(self);}release(value->value);}', 'changed_802bdd24(self);}}')],
    'cx13b_paired_interfaces_assign_802bc098.cpp': [('self->second=second->value;release(first->value);release(second->value);}', 'self->second=second->value;}')],
    's20_small_w.cpp': [('*(Ptr32<unsigned char>)(self + 24) = *(Ptr32<unsigned char>)(source + 4);', '*(Ptr32<unsigned char>)(self + 27) = *(Ptr32<unsigned char>)(source + 4);'), ('*(Ptr32<unsigned char>)(self + 25) = *(Ptr32<unsigned char>)(source + 5);', '*(Ptr32<unsigned char>)(self + 26) = *(Ptr32<unsigned char>)(source + 5);')],
}


# Las bajadas de clase deben ajustar el puntero en herencia múltiple: ver w3d::sc en w3d_ptr.h.
STATIC_DOWN = re.compile(r'\bstatic_cast<(\s*(?:const\s+)?\w+(?:::\w+)*\s*\*)\s*>\(')


# Etiqueta {a, b; palabra}: el byte de flags en +7 (PPC) es el byte bajo de la palabra de +4, que en el anfitrión está en +4.
TAG_BYTE = re.compile(r'((?:unsigned )?char) (\w+)\[(?:7|0x7)\];(\s*)((?:unsigned )?char) (\w+);')
OBJECT_TAG_BYTE = re.compile(r'((?:unsigned )?char) (\w+)\[(?:11|0xB|0xb)\];(\s*)unsigned char (\w+);')
TAG_M2C = re.compile(r'(M2C_FIELD\([^,;]+, *[us]8 *\*, *)(0x7|7|0xB)\)')


# Las macros no pasan por el convertidor: las tablas virtuales declaradas en ellas siguen con punteros de 8 B.
MACRO_VT = [('int (*query_08)(Type *self); \\', 'Ptr32<int (Ptr32<Type>)> query_08; \\'), ('int (*add_ref)(Type *self); \\', 'Ptr32<int (Ptr32<Type>)> add_ref; \\'), ('int (*release)(Type *self)', 'Ptr32<int (Ptr32<Type>)> release')]


GET_RANGE_LOCAL = 'Ptr32<void> data;((Ptr32<void (Ptr32<Item>, Ptr32<Ptr32<void>>)>)buffer.p->v[10])'
GET_RANGE_CALL = ('struct{Ptr32<void> p;unsigned n[2];}range;(buffer.p,&data);', 'struct{Ptr32<void> p;unsigned n[2];}range;((Ptr32<void (Ptr32<Item>, Ptr32<void>)>)buffer.p->v[10])(buffer.p,&range);')

def apply(path):
    text = open(path, errors='replace').read()
    if path.endswith(('b_types2.h', 'b_types.h')) and MACRO_VT[0][0] in text:
        for a, b in MACRO_VT: text = text.replace(a, b)
        open(path, 'w').write(text)
    for a, b in (('(Ptr32<volatile unsigned char>)sub)[7]', '(Ptr32<volatile unsigned char>)sub)[4]'), ('*(Ptr32<unsigned char>)(flags + 7)', '*(Ptr32<unsigned char>)(flags + 4)'), ('*(Ptr32<unsigned char>)(item + 11)', '*(Ptr32<unsigned char>)(item + 8)')):
        if a in text: text = text.replace(a, b); open(path, 'w').write(text)
    if '/vendor/' not in path and (OBJECT_TAG_BYTE.search(text) or 'int u0; unsigned char u4[3]; unsigned char bits;' in text):
        text = OBJECT_TAG_BYTE.sub(lambda m: f'{m[1]} {m[2]}[8];{m[3]}unsigned char {m[4]}; char w3d_tag_rest[3];', text).replace('int u0; unsigned char u4[3]; unsigned char bits;', 'int u0; unsigned char bits; unsigned char u4[3];')
        open(path, 'w').write(text)
    if '/vendor/' not in path and (TAG_BYTE.search(text) or TAG_M2C.search(text)):
        text = TAG_BYTE.sub(lambda m: f'{m[1]} {m[2]}[4];{m[3]}{m[4]} {m[5]}; char w3d_tag_rest[3];', text)
        text = TAG_M2C.sub(lambda m: m[1] + ('0x8)' if m[2] == '0xB' else '0x4)'), text)
        open(path, 'w').write(text)
    if 'static_cast<' in text and STATIC_DOWN.search(text) and not path.endswith('w3d_ptr.h') and '/vendor/' not in path:
        text = STATIC_DOWN.sub(lambda m: f'w3d::sc<{m[1]}>(', text); open(path, 'w').write(text)
    # new (p) T*(v) escribiría 8 B en un hueco de 4 B y pisaría lo siguiente.
    if '/vendor/' not in path and PLACE_PTR.search(text):
        text = PLACE_PTR.sub(lambda m: f'*(Ptr32<{m[2]}> *)w3d::w3d_any_host({m[1]}) = Ptr32<{m[2]}>({m[3]});', text); open(path, 'w').write(text)
    # Un método virtual que devuelve una referencia deja un puntero de 32 bits en w0.
    if '/vendor/' not in path and VIRTUAL_REF.search(text):
        text = VIRTUAL_REF.sub(lambda m: f'Ptr32<w3d::Ref32<{m[1]}>(Ptr32<', text); open(path, 'w').write(text)
    # new[] y delete[] con la cabecera de GCC 2.95 (ver w3d::new_array): hay destructores admitidos o traducidos que la leen.
    if '/vendor/' not in path and ('new ' in text or 'delete' in text) and (NEW_ARRAY.search(text) or DELETE_ARRAY.search(text)):
        text = NEW_ARRAY.sub(lambda m: f'w3d::new_array<{m[1].strip()}>({m[2]})', text)
        text = DELETE_ARRAY.sub(lambda m: f'{m[1]}w3d::delete_array({m[2].strip()});', text)
        open(path, 'w').write(text)
    if '/d24i_grid_' in path and GRID_LINK.search(text):
        # Celda de la rejilla: palabra con el vínculo A en la mitad baja (PPC +2, anfitrión +0).
        text = GRID_LINK.sub(lambda m: f'corner[{int(m[1]) - 1}]', text); open(path, 'w').write(text)
    if LOST_THIS.search(text):
        # M2C pierde el this cuando r3 ya es el valor devuelto por la llamada anterior.
        text = LOST_THIS.sub(lambda m: f'M2C_FIELD(*{m[1]}, Ptr32<{m[2]} (Ptr32<Ptr32<void>>)> *, {m[3]})({m[1]})', text); open(path, 'w').write(text)
    for a, b in RECORD_BYTES.get(__import__('os').path.basename(path), []):
        if a in text: text = text.replace(a, b); open(path, 'w').write(text)
    # El método escribe puntero, tamaño y capacidad; en PPC los 12 B cabían en el marco por casualidad, aquí pisan x20.
    if GET_RANGE_LOCAL in text:
        text = text.replace(GET_RANGE_LOCAL, 'struct{Ptr32<void> p;unsigned n[2];}range;').replace(GET_RANGE_CALL[0], GET_RANGE_CALL[1]).replace('fn_802eee50(out,data,0x11800)', 'fn_802eee50(out,range.p,0x11800)')
        open(path, 'w').write(text)
    if 'w3d_request_hardware_post(r->backend' in text and ARAM_POST.search(text):
        text = ARAM_POST.sub(lambda m: m[2] + '\n' + m[1], text); open(path, 'w').write(text)
    if UNSET_TEXT in text:
        open(path, 'w').write(text.replace(UNSET_TEXT, UNSET_TEXT.replace('stored;', 'stored = 0;')))
        text = open(path, errors='replace').read()
    if TYPE_ID_THEN_COUNT in text or EXPR_COUNT in text:
        open(path, 'w').write(text.replace(TYPE_ID_THEN_COUNT, 'unsigned short count;\n    unsigned short :6; unsigned short type_id:10;').replace(EXPR_COUNT, '(&(*new_var))) + 0x20)'))
        text = open(path, errors='replace').read()
    if CHAR_AS_SHORT in text:
        open(path, 'w').write(text.replace(CHAR_AS_SHORT, 'sp8 = arg1 & 0xff;\n    fn_8020BF2C('))
        text = open(path, errors='replace').read()
    new, n = PATTERN.subn(lambda m: f'unsigned char {m[1]}[0x20];{m[2]}unsigned short {m[3]}; unsigned short w3d_flags_high;', text)
    if n: open(path, 'w').write(new)
    return n
