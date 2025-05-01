# miniRT

## General rules 📏
### Coding ⌨️
- Use a static function whenever is possible (must not appered in the header).
- All functions in the header should be organized like the files.
- The function must not be named `ft_*.c`.
- Try to comment as much as possible on the functions.
- Comments should be in a format similar to :
```c
/**
 * @brief Copy the first size-1 characters of a source to a destination and
 * finish with \0.
 * @details If the source size is less than size-1, copy the source to the destination.
 * @param dst the destination
 * @param src the source
 * @param size the number of character copied.
 * @return Source size.
 * @warning Destination size is not verified.
 */
int	ft_strlcpy(char *dst, const char *src, int size){}
```


### Project Managment 📜
- Respect the [Git Organisation](#git-organisation)
- A branch must be created for each feature
- Merge on the `main` branch as soon as a feature is done
- Commit title must be formated like `KEY_WORD: commit title` with the followings key_words:
  - **ADD**
  - **UPDATE**
  - **REMOVE**
  - **FIX**
  - **WIP** (Work In Progress)
```bash
git commit -m 'KEY_WORD: commit title' -m 'commit description'
```
### Menu management ☰
- Press M to open the menu selection
- Press O to open the obj menu
- Press L to open the light menu
- Press N to switch to the next element
- Press ↑ or ↓ to select the data you will modify
- Press ← or → to decrement or increment the data was selected




## Git Organisation
### Work in your branch
See all branches in local (and what is the current branch)
```bash 
git branch
```
See all branches (and what is the current branch)
```bash 
git branch -a
```
Create a new branch `branch_name`
```bash
git branch <branch_name>
```
Remove a branch `branch_name` (before remove the local branch)
```bash
git push <remote> -d <branch_name>
```
Remove a local branch `branch_name` (think to switch on an other branch before)
```bash
git branch -d <branch_name>
```
Switch to a branch `branch_name`
```bash
git switch <branch_name>
```
Log
```bash
git log
```
Initialize the log at the begining of the project
```bash
git config --global alias.adog "log --all --decorate --oneline --graph"
```
Better log
```bash
git adog
```
### Update a local branch
```bash
git switch <branch>
git pull
```
### Update your branch with current `main`
1. Switch to your branch (if you are on another) and push to ensure your branch is up-to-date before merging
```bash
git switch <branch_name>
git push
```
2. Get the update version of main and add it in your branch
```bash
git pull <remote> main
```
### Merge
1. Switch to `main`
```bash
git switch main
```
2. Update the local `main`
```bash
git pull
```
3. Merge your work in `main`
```bash
git merge <branch_name>
```
4. Fix conflicts and check that everything is working properly

5. Add modifications
 ```bash
git status
git add <files>
``` 
6. Commit the modifications
```bash
git merge --continue
```
7. Push modification
```bash
git push
```

- To cancel a merge (impossible if the merge is committed)
```bash
git merge --abort
```
### Rebase
1. Switch to `main`
```bash
git switch main
```
2. Update the local `main`
```bash
git pull
```
3. Rebase your work in `main`
```bash
git rebase <branch_name>
```
4. Fix conflicts

5. Add modifications
 ```bash
git status
git add <files>
``` 
6. Pass to the next commit
```bash
git rebase --continue
```
7. Push modification
```bash
git push
```

- To cancel a rebase (cancel at the last `--continue`)
```bash
git rebase --abort
```
### Git Helper
Change the message of the last commit
```bash
git commit --amend
```
Cancel the last commit (go back just before validate the last commit)
```bash
git reset --soft HEAD~1
```
Remove the last commit (remove commit and modifications)
```bash
git reset --hard HEAD~1
```

## Link
### Raytracing
[Basic Raytracing](https://www.gabrielgambetta.com/computer-graphics-from-scratch/02-basic-raytracing.html)

[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

[Ray Tracer in Computer Graphics](https://physique.cmaisonneuve.qc.ca/svezina/nyc/note_nyc/NYC_CHAP_6_IMPRIMABLE_4.pdf)

[Realistic Surface Rendering](https://www.research.autodesk.com/app/uploads/2023/03/rendu-realiste-de-surfaces.pdf_reckRMcEDKfhimCkK.pdf)

[Compute Graphics Notes](https://anirudh-s-kumar.github.io/CG-Notes/#my-personal-review-of-the-course)


### Quaternions
[Quaternion - Wikipedia](https://en.wikipedia.org/wiki/Quaternion)

[Quaternion - Wikipedia fr](https://fr.wikipedia.org/wiki/Quaternion)

[Quaternions and spatial rotation - Wikipedia](https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation)

[Quaternions and spatial rotation - Wikipedia fr](https://fr.wikipedia.org/wiki/Quaternions_et_rotation_dans_l%27espace)

[Implementing Quaternions in C++](https://www.haroldserrano.com/blog/developing-a-math-engine-in-c-implementing-quaternions)

[Rotations, Orientation and Quaternions](https://ch.mathworks.com/help/fusion/ug/rotations-orientation-and-quaternions.html)


### Math
[Cylinder Formula - Stack Overflow](https://stackoverflow.com/questions/73866852/ray-cylinder-intersection-formula)

[Object Formula](https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm)

[Change of basis - Wikipedia](https://en.wikipedia.org/wiki/Change_of_basis)

[Change of basis - Wikipedia fr](https://fr.wikipedia.org/wiki/Changement_de_base_(alg%C3%A8bre_lin%C3%A9aire))

[Atan2 - Wikipedia](https://en.wikipedia.org/wiki/Atan2)

[Sphere - Wikipedia](https://en.wikipedia.org/wiki/Sphere)


### Camera
[Orientation - Stack Exchange](https://gamedev.stackexchange.com/questions/121654/getting-the-right-vector-from-the-forward-vector)

[3D Camera Rotation (Unwanted Roll) - Space/Flight Cam - Stack Exchange](https://gamedev.stackexchange.com/questions/183748/3d-camera-rotation-unwanted-roll-space-flight-cam)

[Why rotate an object on two axes, twist around the third? - Stack Exchange](https://gamedev.stackexchange.com/questions/136174/im-rotating-an-object-on-two-axes-so-why-does-it-keep-twisting-around-the-thir)


### GeoGebra
[GeoGebra 3D](https://www.geogebra.org/3d)

[Dot Product](https://www.geogebra.org/m/Yu6869By)

[Cross Product](https://www.geogebra.org/m/psMTGDgc)


### UV
[UV Coordinates Mapped (with animation) - Stack Overflow](https://gamedev.stackexchange.com/questions/197931/how-can-i-correctly-map-a-texture-onto-a-sphere)

[Spherical coordinate system - Wikipedia](https://en.wikipedia.org/wiki/Spherical_coordinate_system)

[Cylindrical coordinate system - Wikipedia](https://en.wikipedia.org/wiki/Cylindrical_coordinate_system)


### Normal mapping
[Advanced Ray Tracer - Medium](https://medium.com/@Ksatese/advanced-ray-tracer-part-4-87d1c98eecff)

[Compute sphere tangent for normal mapping - Stack Exchange](https://computergraphics.stackexchange.com/questions/5498/compute-sphere-tangent-for-normal-mapping)

[](https://learnopengl.com/Advanced-Lighting/Normal-Mapping)

[Normal Mapping - Learn OpenGL](https://learnopengl.com/Advanced-Lighting/Normal-Mapping)

[Normal Mapping - Wikipedia](https://en.wikipedia.org/wiki/Normal_mapping)
