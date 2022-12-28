# input $1 the path, $2 input file, $3 output file.
# statistics removal the outliers.
/home/dhn/github/awesome_indoor_reconstruction/indoor_reconstrucion/PointCloudProcessing/build/statistical_removal --input $1/scan_clean/$2 --output $1/scan_clean/$3
# from point cloud into the mesh.
mkdir $1/surface_reconstruction
# generate the normal
/home/dhn/github/awesome_indoor_reconstruction/indoor_reconstrucion/FaroGroundTruthGenerator/build/NormalEstimator -i $1/scan_clean/scan_alignment.mlp -o $1/surface_reconstruction/point_cloud_with_normals.ply --neighbor_count 8
# possion reconstruction
/home/dhn/github/awesome_indoor_reconstruction/indoor_reconstrucion/AdaptiveSolvers/Bin/Linux/PoissonRecon --in $1/surface_reconstruction/point_cloud_with_normals.ply --out $1/surface_reconstruction/surface.ply --depth 10 --colors --data 16 --density