/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_panel_build_80105ac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
c0_8044b64c = 0x8044b64c;
c1_8044b65c = 0x8044b65c;
c2_8044b66c = 0x8044b66c;
class_80415b40 = 0x80415b40;
class_80415ba0 = 0x80415ba0;
class_80415c00 = 0x80415c00;
class_80415c30 = 0x80415c30;
class_80415cb0 = 0x80415cb0;
class_80415d00 = 0x80415d00;
create_8020b680 = 0x8020b680;
find_801d0858 = 0x801d0858;
list_append_801ef174 = 0x801ef174;
memcpy = 0x802eee50;
panels_8044b694 = 0x8044b694;
release_802134fc = 0x802134fc;
SECTIONS {
  .text.d31i_panel_build_80105ac8 0x80105ac8 : { *(.text.d31i_panel_build_80105ac8) }
  .rodata 0x803998a8 : { *(.rodata) }
  .sdata 0x804af1dc (NOLOAD) : {
    . = 0x0; guard_804af1dc = .;
    . = 0x4; guard_804af1e0 = .;
    . = 0x8; guard_804af1e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
