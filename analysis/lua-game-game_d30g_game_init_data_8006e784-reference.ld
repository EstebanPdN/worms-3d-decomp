/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30g_game_init_data_8006e784)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
cast_80341584 = 0x80341584;
data_80179598 = 0x80179598;
elapsed_801fe45c = 0x801fe45c;
lookup_800fc1b0 = 0x800fc1b0;
memset = 0x802eefe0;
printf = 0x802ebfbc;
random_80162ba8 = 0x80162ba8;
s_8037c454 = 0x8037c454;
s_8037c474 = 0x8037c474;
seed_a_80162c18 = 0x80162c18;
seed_b_80162c90 = 0x80162c90;
SECTIONS {
  .text.w3d_d30g_game_init_data_8006e784 0x8006e784 : { *(.text.w3d_d30g_game_init_data_8006e784) }
  .sdata 0x804aaac8 (NOLOAD) : {
    . = 0x0; rounds_804aaac8 = .;
    . = 0xff8; ready_804abac0 = .;
    . = 0x6cc0; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
