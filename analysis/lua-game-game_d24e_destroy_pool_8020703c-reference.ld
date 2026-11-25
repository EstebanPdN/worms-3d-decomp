/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_destroy_pool_8020703c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1f8 = 0x801fe1f8;
fn_802074c4 = 0x802074c4;
fn_80210990 = 0x80210990;
fn_80210abc = 0x80210abc;
fn_802134fc = 0x802134fc;
memcpy = 0x802eee50;
vt_804191c0 = 0x804191c0;
vt_80419200 = 0x80419200;
SECTIONS {
  .text.w3d_d24e_destroy_pool_8020703c 0x8020703c : { *(.text.w3d_d24e_destroy_pool_8020703c) }
  .sdata 0x804b18f0 (NOLOAD) : {
    . = 0x0; count_804b18f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
