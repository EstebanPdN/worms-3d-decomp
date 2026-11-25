/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_weapon_attach_trail_8013f5c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801222cc = 0x801222cc;
FUN_8013f6b4 = 0x8013f6b4;
FUN_80164514 = 0x80164514;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_80410b08 = 0x80410b08;
w3d_str_8039fdcc = 0x8039fdcc;
w3d_str_8039fddc = 0x8039fddc;
w3d_str_8039fde4 = 0x8039fde4;
w3d_string_from_text = 0x8020bb54;
SECTIONS {
  .text.k4a_weapon_attach_trail_8013f5c4 0x8013f5c4 : { *(.text.k4a_weapon_attach_trail_8013f5c4) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
