# Directory containing test files
TEST_PATH     := test
# Space-separated list of header files (e.g., algebra.h)
HEADERS       :=
# Space-separated list of implementation files (e.g., algebra.cc)
IMPLEMS       := salary.cc
# File containing main
DRIVER        := main.cc
# Expected name of executable file
EXECFILE      := main
CLANGTDY_CHKS := *,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard
