/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006e004)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178d1c = 0x80178d1c;
w3d_engine_get_context = 0x80165254;
w3d_fn_800e64e8 = 0x800e64e8;
w3d_fn_800fd4c8 = 0x800fd4c8;
w3d_fn_800fd504 = 0x800fd504;
w3d_str_8037c3c8 = 0x8037c3c8;
SECTIONS {
  .text.w3d_fn_8006e004 0x8006e004 : { *(.text.w3d_fn_8006e004) }
  .text.w3d_fn_8006eebc 0x8006eebc : { *(.text.w3d_fn_8006eebc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
