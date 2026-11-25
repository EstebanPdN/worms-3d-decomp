/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__9D28bWater)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13List_801f2678 = 0x801f2678;
_vt.9D28bWater = 0x8040f150;
lbl_80414840 = 0x80414840;
lbl_80415b00 = 0x80415b00;
lbl_80415ba0 = 0x80415ba0;
lbl_80415bb0 = 0x80415bb0;
lbl_80415bd0 = 0x80415bd0;
lbl_80415c00 = 0x80415c00;
lbl_80415c10 = 0x80415c10;
lbl_80415c30 = 0x80415c30;
lbl_80415cb0 = 0x80415cb0;
lbl_80431e58 = 0x80431e58;
lbl_80431e68 = 0x80431e68;
lbl_80431e78 = 0x80431e78;
lbl_8045e748 = 0x8045e748;
w3d_append_801ef174 = 0x801ef174;
w3d_array_ref_lock_801ef048 = 0x801ef048;
w3d_bit_table_8008f410 = 0x8008f410;
w3d_create_8020b680 = 0x8020b680;
w3d_heap_alloc_802098d8 = 0x802098d8;
w3d_light_tables_8008f7c4 = 0x8008f7c4;
w3d_read_800fc1b0 = 0x800fc1b0;
w3d_read_800fc2b0 = 0x800fc2b0;
w3d_read_800fc330 = 0x800fc330;
w3d_unit_table_8008f478 = 0x8008f478;
SECTIONS {
  .text.__9D28bWater 0x8008fb3c : { *(.text.__9D28bWater) }
  .rodata 0x8037e808 : { *(.rodata) }
  .sdata 0x804aab68 (NOLOAD) : {
    . = 0x0; lbl_804aab68 = .;
    . = 0x324c; lbl_804addb4 = .;
    . = 0x3250; lbl_804addb8 = .;
    . = 0x3254; lbl_804addbc = .;
    . = 0x327c; lbl_804adde4 = .;
    . = 0x6c90; lbl_804b17f8 = .;
    . = 0x6c98; lbl_804b1800 = .;
    . = 0x6c9c; lbl_804b1804 = .;
    . = 0x6ca0; lbl_804b1808 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
