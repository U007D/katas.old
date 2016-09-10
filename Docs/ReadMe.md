# EmptyProject

### Installation Instructions
*These instructions work in a Bash environment.  If you are on Windows,
Bash is now officially supported!  (Windows 10 required).
Installation instructions can be found [here](https://msdn.microsoft.com/en-us/commandline/wsl/install_guide).*

- Clone the repository to the desired location on your system
    - eg. `git clone git@github.com:bradleygibson/EmptyProject.git [your-project-name]`


- `cd` into the repository
    - `cd [your-project-name]`


- Retrieve submodule repositories
    - `git submodule init && git submodule update`


- Set submodules to correct versions (or skip this step if you want to be on the latest version of a given submodule)
    - *NOTE: When performing this step, you will see messages
      from git about 'detached head state'.  This is normal.*
    - **Catch**:
        - `pushd Source/Tests/Submodules/3rdParty/Catch && git checkout tags/v1.5.6 && popd`


- Your project is ready for use!