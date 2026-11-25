/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_apply_texture_80168af0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016803c = 0x8016803c;
fn_8016804c = 0x8016804c;
fn_8016c014 = 0x8016c014;
fn_801a2bf4 = 0x801a2bf4;
fn_801a314c = 0x801a314c;
fn_801a3164 = 0x801a3164;
fn_801a3190 = 0x801a3190;
fn_803080a4 = 0x803080a4;
fn_8030ae60 = 0x8030ae60;
fn_8030ae84 = 0x8030ae84;
fn_8030b648 = 0x8030b648;
SECTIONS {
  .text.w3d_s20_apply_texture_80168af0 0x80168af0 : { *(.text.w3d_s20_apply_texture_80168af0) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
