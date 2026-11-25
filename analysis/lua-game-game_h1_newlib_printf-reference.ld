/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fprintf)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_vfprintf_802f06c8 = 0x802f06c8;
SECTIONS {
  .text.fprintf 0x802eb50c : { *(.text.fprintf) }
  .text.printf 0x802ebfbc : { *(.text.printf) }
  .text.sprintf 0x802ec254 : { *(.text.sprintf) }
  .text.vsprintf 0x802ed5e0 : { *(.text.vsprintf) }
  .text.vsnprintf 0x802ed63c : { *(.text.vsnprintf) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; w3d_sda_impure_ptr_804ac570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
