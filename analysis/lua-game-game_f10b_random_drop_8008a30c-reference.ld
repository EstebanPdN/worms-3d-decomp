/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f10b_random_drop_8008a30c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
active_8008e224 = 0x8008e224;
append_80089eec = 0x80089eec;
camera_8037dad8 = 0x8037dad8;
count_8037d930 = 0x8037d930;
defaults_8008a044 = 0x8008a044;
delay_8037d9f4 = 0x8037d9f4;
file_8037db3c = 0x8037db3c;
get_80178c48 = 0x80178c48;
health_8037db0c = 0x8037db0c;
log_80022e20 = 0x80022e20;
nodrop_8037db24 = 0x8037db24;
number_800fc1f0 = 0x800fc1f0;
pot_8037db04 = 0x8037db04;
random_80162ba8 = 0x80162ba8;
randompos_8037da18 = 0x8037da18;
read_800fc330 = 0x800fc330;
scheme_8037daf4 = 0x8037daf4;
set_800fc3b0 = 0x800fc3b0;
shower_8037da08 = 0x8037da08;
teams_8008c34c = 0x8008c34c;
text_800fc550 = 0x800fc550;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
type_8037da60 = 0x8037da60;
utility_8008a76c = 0x8008a76c;
weapon_8008a66c = 0x8008a66c;
SECTIONS {
  .text.f10b_random_drop_8008a30c 0x8008a30c : { *(.text.f10b_random_drop_8008a30c) }
  .sdata 0x804aab40 (NOLOAD) : {
    . = 0x0; health_804aab40 = .;
    . = 0x4; weapon_804aab44 = .;
    . = 0x8; utility_804aab48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
