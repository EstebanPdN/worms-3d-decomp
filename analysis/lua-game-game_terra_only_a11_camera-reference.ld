/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_a11_camera_80036218)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_80342a74 = 0x80342a74;
lbl_80373c3c = 0x80373c3c;
lbl_80373c58 = 0x80373c58;
lbl_80373c74 = 0x80373c74;
SECTIONS {
  .text.terra_only_a11_camera_80036218 0x80036218 : { *(.text.terra_only_a11_camera_80036218) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
