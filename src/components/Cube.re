let component = ReasonReact.statelessComponent("Cube");

type _3dCoOd = {
  x: int,
  y: int,
  z: int,
};

type _2dCoOd = (int, int);

type cubeIn2d = list(_2dCoOd);

type triangle =
  | LeftSide
  | RightSide
  | LeftTop
  | RightTop
  | LeftFront
  | RightFront;

let _2dTransform = (center: _3dCoOd) => {
  let x = center.x;
  let y = center.y;
  let z = center.z;
  [
    (x - y, x + y + 2 * z),
    (x - y, x + y + 2 * z + 1),
    (x - y, x + y + 2 * z + 2),
    (x - y + 1, x + y + 2 * z),
    (x - y + 1, x + y + 2 * z + 1),
    (x - y + 1, x + y + 2 * z + 2),
  ];
};

let xOrigin = (side: int, triangle: triangle) => {
  let edgeH = float_of_int(side) *. sqrt(3.0) /. 2.0;
  let x =
    switch (triangle, edgeH) {
    | (LeftSide | RightSide | LeftTop, _edgeH) => 0.0
    | (RightFront | LeftFront | RightTop, edgeH) => edgeH
    };
  350.0 -. edgeH +. x;
};

/* let _2dTranform = (center: _3dPosition, edge) => {
     let x = float_of_int(center.x);
     let y = float_of_int(center.y);
     let z = float_of_int(center.z);
     let edgeH = edge *. sqrt(3.0) /. 2.0;
     let edgeV = edge /. 2.0;
     let x_index = x *. edgeH -. y *. edgeH;
     let y_index = x *. edgeV +. y *. edgeV +. z *. edge;
     {x: x_index, y: y_index};
   }; */
let make = (~center: _3dCoOd, ~side: int, _children) => {
  ...component,
  render: _self =>
    /* let sideAsFloat = float_of_int(side);
       let left =
         string_of_float(_2dTranform(center, sideAsFloat).x +. 350.0) ++ "px";
       let top =
         string_of_float(350.0 -. _2dTranform(center, sideAsFloat).y) ++ "px";
       let zIndex = string_of_int(100 - (center.x + center.y - center.z));
       let offsetSyle = ReactDOMRe.Style.make(~left, ~top, ~zIndex, ());
       let sideAsString = string_of_int(side) ++ "px";
       let faceStyle =
         ReactDOMRe.Style.make(~width=sideAsString, ~height=sideAsString, ()); */
    <div className="cube">
      <div className="triangle left-side" />
      <div className="triangle right-side" />
      <div className="triangle left-top" />
      <div className="triangle right-front" />
      <div className="triangle left-front" />
      <div className="triangle right-top" />
    </div>,
};