/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40k_scheme_list_page_80271518)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__12Str_803426b8 = 0x803426b8;
__12Str_803426b8PCc = 0x8020bb54;
fn_800fc668 = 0x800fc668;
fn_800fc69c = 0x800fc69c;
fn_80179598 = 0x80179598;
fn_801797b4 = 0x801797b4;
fn_8020bb2c = 0x8020bb2c;
fn_8020bf2c = 0x8020bf2c;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80210afc = 0x80210afc;
fn_80210d54 = 0x80210d54;
fn_8027a934 = 0x8027a934;
fn_802cbdf8 = 0x802cbdf8;
fn_802cbf2c = 0x802cbf2c;
fn_802cc0ac = 0x802cc0ac;
fn_802cd128 = 0x802cd128;
fn_802cd220 = 0x802cd220;
fn_802cd26c = 0x802cd26c;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
free = 0x802134fc;
lbl_80366118 = 0x80366118;
lbl_803cc4f8 = 0x803cc4f8;
lbl_803cc50c = 0x803cc50c;
lbl_803cc510 = 0x803cc510;
lbl_803cc514 = 0x803cc514;
lbl_803cc524 = 0x803cc524;
lbl_803cc528 = 0x803cc528;
lbl_803cc534 = 0x803cc534;
lbl_803cc57c = 0x803cc57c;
lbl_804b06a0 = 0x804b06a0;
malloc = 0x80212fd4;
SECTIONS {
  .text.w3d_d40k_scheme_list_page_80271518 0x80271518 : { *(.text.w3d_d40k_scheme_list_page_80271518) }
  .sdata 0x804abba0 (NOLOAD) : {
    . = 0x0; lbl_804abba0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
