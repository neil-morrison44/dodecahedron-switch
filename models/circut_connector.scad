use <./half.scad>
$fn = 360;

$screwRadius = 2.26 / 2;
$tileRadius = 25;

$height = 6;

$boardThickness = 1.15;

$clipHeight = 8;
$clipWidth = 8;

module connector() {
    difference() {
        cylinder($fn = 6, r = 10, h = $height);

        for (i = [0:360 / 3:360]) {
            rotate([ 0, 0, i ]) translate([ $tileRadius / 4, 0, -0.1 ]) {
                cylinder($height + 1, $screwRadius, $screwRadius);
                translate([ 0, 0, $height - 0.5 ])
                    cylinder(0.65, $screwRadius, $screwRadius + 0.5);
            }
        }
    }
}

module boardClip() {
    translate([ 0, 0, ($clipHeight / 2) + $height ]) {
        difference() {
            hull() {
                cube([ $boardThickness * 2, $clipWidth, $clipHeight ], true);
                for (i = [ -3, 3 ]) {
                    translate([ i, 0, -($clipHeight / 2) ]) {
                        cube([ $boardThickness * 2, 2, 0.1 ], true);
                    }
                }
            }
            cube([ $boardThickness, $clipWidth + 2, $clipHeight + 1 ], true);
            // lips
            translate([0,($clipWidth + 1) / 2,$clipHeight / 2])
            rotate([90, 0, 0])
            cylinder($clipWidth + 1, $boardThickness /1.5, $boardThickness / 1.5);
            
            //screwHole
            
            translate([-5, 0, 0])
            rotate([0, 90, 0])
            cylinder(10, $screwRadius, $screwRadius);
        }
    }
}

difference() {
    connector();
    scale([ 1, 1, 1.1 ]) translate([ 0, 0, -0.1 ]) screwConnector();
}

boardClip();
