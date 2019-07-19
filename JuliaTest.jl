# Load the module and generate the functions
module CppHello
  using CxxWrap
  @wrapmodule(joinpath("/home/bhattadn/Workspace/C++","libtest"))

  function __init__()
    @initcxx
  end
end

# Call greet and show the result
@show CppHello.greet()
