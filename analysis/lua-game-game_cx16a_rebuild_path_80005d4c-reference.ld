/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16a_rebuild_path_80005d4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
call_80004394 = 0x80004394;
call_80005398 = 0x80005398;
call_80005858 = 0x80005858;
call_80005e1c = 0x80005e1c;
call_80015264 = 0x80015264;
call_8034144c = 0x8034144c;
SECTIONS {
  .text.w3d_cx16a_rebuild_path_80005d4c 0x80005d4c : { *(.text.w3d_cx16a_rebuild_path_80005d4c) }
  .sdata 0x804aa794 (NOLOAD) : {
    . = 0x0; enabled_804aa794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
