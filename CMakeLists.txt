# Definir a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(ArtGenerator C)

# Adicionar o diretório de includes para os headers
include_directories(src/types/board src/types/menu src/types/utils)

# Adicionar todos os arquivos fontes
add_executable(ArtGenerator 
    src/main.c
    src/types/board/board.c
    src/types/menu/menu.c
    src/types/utils/utils.c
)

# Incluir a biblioteca padrão do sistema
target_link_libraries(ArtGenerator m)
