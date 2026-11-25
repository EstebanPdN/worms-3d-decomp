/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_read_tga_801da28c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d9f0c = 0x801d9f0c;
fn_801d9fb0 = 0x801d9fb0;
lbl_803af9dc = 0x803af9dc;
lbl_803afa00 = 0x803afa00;
lbl_803afa04 = 0x803afa04;
lbl_803afa18 = 0x803afa18;
lbl_803afa2c = 0x803afa2c;
lbl_803afa48 = 0x803afa48;
lbl_803afa6c = 0x803afa6c;
lbl_803afa90 = 0x803afa90;
lbl_803afab4 = 0x803afab4;
lbl_803afacc = 0x803afacc;
lbl_803afaf0 = 0x803afaf0;
lbl_803afb14 = 0x803afb14;
lbl_803afb40 = 0x803afb40;
lbl_803afb5c = 0x803afb5c;
lbl_803afb74 = 0x803afb74;
lbl_803afb94 = 0x803afb94;
lbl_803afbb0 = 0x803afbb0;
lbl_803afbdc = 0x803afbdc;
lbl_803afbfc = 0x803afbfc;
lbl_803afc28 = 0x803afc28;
lbl_803afc44 = 0x803afc44;
lbl_803afc68 = 0x803afc68;
lbl_803afca0 = 0x803afca0;
lbl_803afcd4 = 0x803afcd4;
lbl_803afd0c = 0x803afd0c;
lbl_803afd3c = 0x803afd3c;
lbl_803afd60 = 0x803afd60;
lbl_803afd8c = 0x803afd8c;
lbl_803afdbc = 0x803afdbc;
lbl_8045d818 = 0x8045d818;
memcmp = 0x802eedc0;
memset = 0x802eefe0;
printf = 0x802ebfbc;
sprintf = 0x802ec254;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d30e_read_tga_801da28c 0x801da28c : { *(.text.w3d_d30e_read_tga_801da28c) }
  .sdata 0x804ab800 (NOLOAD) : {
    . = 0x0; lbl_804ab800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
