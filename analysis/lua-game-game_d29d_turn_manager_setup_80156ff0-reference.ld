/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29d_turn_manager_setup_80156ff0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
bind_800fc1b0 = 0x800fc1b0;
defaults_8015776c = 0x8015776c;
message_id_8015f5a0 = 0x8015f5a0;
str_803a27ac = 0x803a27ac;
str_803a27f0 = 0x803a27f0;
str_803a2b4c = 0x803a2b4c;
str_803a2b60 = 0x803a2b60;
str_803a2b70 = 0x803a2b70;
str_803a2b84 = 0x803a2b84;
str_803a2b90 = 0x803a2b90;
str_803a2ba0 = 0x803a2ba0;
str_803a2bb8 = 0x803a2bb8;
str_803a2bd0 = 0x803a2bd0;
str_803a2be4 = 0x803a2be4;
str_803a2bf8 = 0x803a2bf8;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
triple_8045e788 = 0x8045e788;
watch_800fd62c = 0x800fd62c;
water_changed_80158fbc = 0x80158fbc;
SECTIONS {
  .text.d29d_turn_manager_setup_80156ff0 0x80156ff0 : { *(.text.d29d_turn_manager_setup_80156ff0) }
  .sdata 0x804afe40 (NOLOAD) : {
    . = 0x0; cache_804afe40 = .;
    . = 0x18; cache_804afe58 = .;
    . = 0x20; cache_804afe60 = .;
    . = 0x28; cache_804afe68 = .;
    . = 0x38; cache_804afe78 = .;
    . = 0x40; cache_804afe80 = .;
    . = 0x58; cache_804afe98 = .;
    . = 0x68; cache_804afea8 = .;
    . = 0x70; cache_804afeb0 = .;
    . = 0x80; cache_804afec0 = .;
    . = 0x90; cache_804afed0 = .;
    . = 0xa0; cache_804afee0 = .;
    . = 0xb8; cache_804afef8 = .;
    . = 0xc0; cache_804aff00 = .;
    . = 0xd0; cache_804aff10 = .;
    . = 0xd8; cache_804aff18 = .;
    . = 0xe8; cache_804aff28 = .;
    . = 0xf0; cache_804aff30 = .;
    . = 0xf8; cache_804aff38 = .;
    . = 0x100; cache_804aff40 = .;
    . = 0x128; cache_804aff68 = .;
    . = 0x130; cache_804aff70 = .;
    . = 0x138; cache_804aff78 = .;
    . = 0x140; cache_804aff80 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
