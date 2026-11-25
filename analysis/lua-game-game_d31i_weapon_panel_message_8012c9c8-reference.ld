/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_weapon_panel_message_8012c9c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
arena_801613f0 = 0x801613f0;
base_8015fb34 = 0x8015fb34;
context_80165254 = 0x80165254;
eq_8015f65c = 0x8015f65c;
finish_8012f77c = 0x8012f77c;
get_800a830c = 0x800a830c;
init_8012d0a4 = 0x8012d0a4;
inner_80178c48 = 0x80178c48;
message_id_8015f5a0 = 0x8015f5a0;
post16_800f90e8 = 0x800f90e8;
post_8016239c = 0x8016239c;
read_uint_800fc230 = 0x800fc230;
refresh_8012d894 = 0x8012d894;
s_8039d9b4 = 0x8039d9b4;
s_8039d9c8 = 0x8039d9c8;
s_8039d9d4 = 0x8039d9d4;
select_8012c7cc = 0x8012c7cc;
strcmp = 0x802ef234;
target_800fc710 = 0x800fc710;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d31i_weapon_panel_message_8012c9c8 0x8012c9c8 : { *(.text.d31i_weapon_panel_message_8012c9c8) }
  .rodata 0x8039d9dc : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; stack_804aa8c8 = .;
    . = 0x4d54; id_804af61c = .;
    . = 0x4d5c; id_804af624 = .;
    . = 0x4d64; id_804af62c = .;
    . = 0x4d74; id_804af63c = .;
    . = 0x4d7c; id_804af644 = .;
    . = 0x4d84; id_804af64c = .;
    . = 0x4d8c; id_804af654 = .;
    . = 0x4d94; id_804af65c = .;
    . = 0x4da4; id_804af66c = .;
    . = 0x4db4; id_804af67c = .;
    . = 0x4dbc; id_804af684 = .;
    . = 0x4dd4; id_804af69c = .;
    . = 0x4dec; id_804af6b4 = .;
    . = 0x4df4; id_804af6bc = .;
    . = 0x4dfc; id_804af6c4 = .;
    . = 0x4e04; id_804af6cc = .;
    . = 0x4e0c; id_804af6d4 = .;
    . = 0x4e14; id_804af6dc = .;
    . = 0x4e1c; id_804af6e4 = .;
    . = 0x4e24; id_804af6ec = .;
    . = 0x4e2c; id_804af6f4 = .;
    . = 0x4e34; id_804af6fc = .;
    . = 0x4e3c; id_804af704 = .;
    . = 0x4e44; id_804af70c = .;
    . = 0x4e5c; id_804af724 = .;
    . = 0x6e8c; arena_804b1754 = .;
    . = 0x6ec0; service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
