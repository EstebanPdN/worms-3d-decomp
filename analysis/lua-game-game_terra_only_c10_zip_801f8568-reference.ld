/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_c10_zip_801f8568)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f8d6c = 0x801f8d6c;
fn_801f9290 = 0x801f9290;
fn_801f937c = 0x801f937c;
fn_801fe1d8 = 0x801fe1d8;
lbl_803b18d8 = 0x803b18d8;
lbl_803b18fc = 0x803b18fc;
lbl_803b191c = 0x803b191c;
printf = 0x802ebfbc;
strncpy = 0x802efbfc;
SECTIONS {
  .text.terra_only_c10_zip_801f8568 0x801f8568 : { *(.text.terra_only_c10_zip_801f8568) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
