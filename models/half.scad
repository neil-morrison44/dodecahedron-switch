$fs = 0.5;
$fa = 0.1;

$tileRadius = 25;
$magnetRadius = 4.1;
$magnetHeight = 2.8;

$tileChafer = 2;

$tileSideLength = (($tileRadius + ($tileChafer)) * sin(72 / 2)) * 2;

$containingSphereRadius = ($tileSideLength / 4) * (sqrt(15) + sqrt(3));

$insideSphereRadius =
    ($tileSideLength / 2) * sqrt((5 / 2) + ((11 / 10) * sqrt(5)));

$screwRadius = 2.25 / 2;

$startNumber = 0;

$dodecNumber = 116.565;

module magnetConnector() {
    translate([ 0, 0, 0 ]) difference() {
        minkowski() {
            cube([ $magnetRadius, $tileRadius / 2, 10 ], true);
            sphere(r = 1);
        }
        rotate([ 0, -90, 0 ]) {
            translate([ 2.75, 0, 0 ]) {
                cylinder($magnetHeight, $magnetRadius, $magnetRadius, true);
                hull() {
                    translate([ -3, 0, 0 ])
                        cylinder($magnetHeight * 3, $magnetRadius / 2,
                                 $magnetRadius / 2, true);
                    cylinder($magnetHeight * 3, $magnetRadius / 2,
                             $magnetRadius / 2, true);
                }
                translate([ $magnetRadius * 0.95, 0, 0 ]) scale([ 1, 1, 1 ])
                    cylinder($magnetHeight, $magnetRadius + 1,
                             $magnetRadius + 1, true);
            }
        }
    }
}

module screwConnector() {
    difference() {
        cylinder($fn = 3, r = $tileRadius / 2, h = 4);

        for (i = [0:360 / 3:360]) {
            rotate([ 0, 0, i ]) translate([ $tileRadius / 4, 0, 0.1 ])
                cylinder(5, $screwRadius, $screwRadius);
        }
    }
}

module pentagon(number = "1", hasMagnets = false, hasScrews = false,
                numberAngle = -90, depth = 1.5) {
    rotate([ 180, 0, 0 ]) {
        difference() {
            union() {
                minkowski() {
                    cylinder($fn = 5, r = $tileRadius, h = 1);
                    sphere(r = $tileChafer);
                }

                if (hasMagnets) {
                    for (angle = [ -(72 / 2), (72 / 2) ]) {
                        rotate([ 0, 0, angle ])
                            translate([ $tileRadius * 0.585, 0, 5 ])
                                rotate([ 0, -($dodecNumber - 90), 0 ])
                                    magnetConnector();
                    }
                }

                if (hasScrews) {
                    translate([ 0, 0, 3 ]) screwConnector();
                }
            }
            scale([ 1, -1, 1 ]) translate([ 0, 0, -(5 + depth) ])
                linear_extrude(height = 5) {
                rotate([ 0, 0, numberAngle ])
                    text(number, size = $tileRadius * 1.1, halign = "center",
                         valign = "center");
            }
        }
    }
}

module bottom() {
    rotate([ 0, 0, -(72 / 2) ]) translate([ 0, 0, $insideSphereRadius ])
        pentagon(number = str($startNumber), hasScrews = true);

    for (i = [0:72:360 - 72]) {
        $number = str((i / 72) + ($startNumber) + 1);
        rotate([ 0, (180 - $dodecNumber), i ])
            translate([ 0, 0, $insideSphereRadius ])
                pentagon(number = $number, hasMagnets = true);
    }
}
moduletop() {
    for (i = [0:72:360 - 72]) {
        $number = str((i / 72) + ($startNumber + 5) + 1);
        rotate([ 0, ($dodecNumber), (-72 / 2) + i ])
            translate([ 0, 0, $insideSphereRadius ]) rotate([ 0, 0, 180 ])
                pentagon(number = $number, hasMagnets = true, numberAngle = 90);
    }
    rotate([ 180, 0, 0 ]) translate([ 0, 0, $insideSphereRadius ]) pentagon(
        number = str($startNumber + 11), hasScrews = true, depth = 0.5);
}
difference() {
    top();
    bottom();
}
