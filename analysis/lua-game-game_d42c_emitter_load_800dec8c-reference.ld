/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42c_emitter_load_800dec8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
build_800e0198 = 0x800e0198;
context_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
motion_800df6c8 = 0x800df6c8;
n1_80389c18 = 0x80389c18;
n2_80389c38 = 0x80389c38;
n3_80389c58 = 0x80389c58;
n4_80389c64 = 0x80389c64;
n5_80389c74 = 0x80389c74;
random_80162bc8 = 0x80162bc8;
read_setting_800fc1b0 = 0x800fc1b0;
sweep_800df570 = 0x800df570;
SECTIONS {
  .text.d42c_emitter_load_800dec8c 0x800dec8c : { *(.text.d42c_emitter_load_800dec8c) }
  .rodata 0x80389c88 : { *(.rodata) }
  .sdata 0x804aecb4 (NOLOAD) : {
    . = 0x0; rng_804aecb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
