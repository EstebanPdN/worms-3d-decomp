/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41i_weapon_select_panel_build_8012d8c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
add_8025cb4c = 0x8025cb4c;
arena_801613f0 = 0x801613f0;
as_table_80341584 = 0x80341584;
attr_800fd014 = 0x800fd014;
box_804668d0 = 0x804668d0;
box_804668dc = 0x804668dc;
buffalo_803fdadc = 0x803fdadc;
callback_8012f368 = 0x8012f368;
class_80419cf8 = 0x80419cf8;
class_80419d78 = 0x80419d78;
class_8041b958 = 0x8041b958;
create_8020b680 = 0x8020b680;
grid_8012fa4c = 0x8012fa4c;
has_8025cbe0 = 0x8025cbe0;
icons_80451a9c = 0x80451a9c;
inner_80178c48 = 0x80178c48;
inner_801797b4 = 0x801797b4;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
message_id_8015f5a0 = 0x8015f5a0;
message_string_init_8010a8e0 = 0x8010a8e0;
named_800a7e14 = 0x800a7e14;
names_803eb63c = 0x803eb63c;
post_8016239c = 0x8016239c;
q_800fc7f8 = 0x800fc7f8;
q_800fca30 = 0x800fca30;
q_800fcc68 = 0x800fcc68;
q_800fcd84 = 0x800fcd84;
random_80161080 = 0x80161080;
read_float_800fc270 = 0x800fc270;
read_int_800fc1f0 = 0x800fc1f0;
read_uint_800fc230 = 0x800fc230;
reason_8012f0f8 = 0x8012f0f8;
s_8039d9a4 = 0x8039d9a4;
s_8039d9b0 = 0x8039d9b0;
s_8039d9e0 = 0x8039d9e0;
s_8039da40 = 0x8039da40;
s_8039da50 = 0x8039da50;
s_8039dae0 = 0x8039dae0;
s_8039daf4 = 0x8039daf4;
s_8039db04 = 0x8039db04;
s_8039db14 = 0x8039db14;
s_8039db24 = 0x8039db24;
s_8039db38 = 0x8039db38;
s_8039db50 = 0x8039db50;
s_8039db60 = 0x8039db60;
s_8039db74 = 0x8039db74;
s_8039db80 = 0x8039db80;
s_8039db94 = 0x8039db94;
s_8039dba8 = 0x8039dba8;
s_8039dbc0 = 0x8039dbc0;
s_8039dbd4 = 0x8039dbd4;
s_8039dbf8 = 0x8039dbf8;
s_8039dc10 = 0x8039dc10;
s_8039dc24 = 0x8039dc24;
s_8039dc38 = 0x8039dc38;
s_8039dc40 = 0x8039dc40;
s_8039dc58 = 0x8039dc58;
s_8039dc68 = 0x8039dc68;
s_8039dc80 = 0x8039dc80;
s_8039dcb8 = 0x8039dcb8;
slot_8012f180 = 0x8012f180;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
table_get_80179598 = 0x80179598;
tag_801ea4c8 = 0x801ea4c8;
team_800fc6dc = 0x800fc6dc;
unsigned_8025c3a8 = 0x8025c3a8;
update_80178d28 = 0x80178d28;
vt_8040db38 = 0x8040db38;
weapons_803fd9e4 = 0x803fd9e4;
SECTIONS {
  .text.d41i_weapon_select_panel_build_8012d8c0 0x8012d8c0 : { *(.text.d41i_weapon_select_panel_build_8012d8c0) }
  .rodata 0x8039dcc0 : { *(.rodata) }
  .sdata 0x804af66c (NOLOAD) : {
    . = 0x0; msg_804af66c = .;
    . = 0x40; msg_804af6ac = .;
    . = 0x20e8; arena_804b1754 = .;
    . = 0x211c; service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
