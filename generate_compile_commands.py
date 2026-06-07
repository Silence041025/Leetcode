import os
import json
import glob

# 标准库路径
includes = [
    "C:/msys64/mingw64/include/c++/15.2.0",
    "C:/msys64/mingw64/include/c++/15.2.0/mingw64",
    "C:/msys64/mingw64/lib/gcc/mingw32/15.2.0/include",
    "C:/msys64/mingw64/include"
]

include_args = " ".join([f"-I{inc}" for inc in includes])

compile_commands = []
for cpp_file in glob.glob("*.cpp"):
    command = f"g++ -c {include_args} {cpp_file}"
    compile_commands.append({
        "directory": os.path.abspath("."),
        "command": command,
        "file": os.path.abspath(cpp_file)
    })

with open("compile_commands.json", "w") as f:
    json.dump(compile_commands, f, indent=2)

print("Generated compile_commands.json for", len(compile_commands), "files")