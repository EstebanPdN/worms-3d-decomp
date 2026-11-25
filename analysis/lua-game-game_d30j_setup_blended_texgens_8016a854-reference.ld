/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_setup_blended_texgens_8016a854)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19d_texgen_scale_offset_8016c130 = 0x8016c130;
fn_803080a4 = 0x803080a4;
fn_8030aab8 = 0x8030aab8;
fn_8030ac30 = 0x8030ac30;
fn_8030ad74 = 0x8030ad74;
fn_8030ae60 = 0x8030ae60;
fn_8030aecc = 0x8030aecc;
fn_8030b648 = 0x8030b648;
w3d_auto_8016803c = 0x8016803c;
w3d_auto_8016c1f4 = 0x8016c1f4;
w3d_d27e_apply_attributes_801a2bf4 = 0x801a2bf4;
SECTIONS {
  .text.d30j_setup_blended_texgens_8016a854 0x8016a854 : { *(.text.d30j_setup_blended_texgens_8016a854) }
  .rodata 0x803a5550 : { *(.rodata) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
