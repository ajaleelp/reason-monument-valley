let component = ReasonReact.statelessComponent("Cube");

type layout = list(Cube._3dPosition);

let make = _children => {
  ...component,
  render: _self => {
    let myLayout: layout = [
      {x: 0, y: 0, z: 0},
      {x: 1, y: 0, z: 0},
      {x: 0, y: 1, z: 0},
      {x: 0, y: 0, z: 1},
      {x: 0, y: 0, z: 2},
      {x: 1, y: 0, z: 2},
      {x: 2, y: 0, z: 2},
      {x: 2, y: 0, z: 3},
      {x: 0, y: 2, z: 0},
      {x: 0, y: 3, z: 0},
      {x: 0, y: 3, z: 1},
      {x: 0, y: 3, z: 2},
      {x: 0, y: 3, z: 3},
      {x: 0, y: 3, z: 4},
      {x: 0, y: 3, z: 5},
      {x: 0, y: 2, z: 5},
      {x: 0, y: 1, z: 5},
      {x: 0, y: 0, z: 5},
      {x: 0, y: (-1), z: 5},
      {x: 0, y: 4, z: 0},
      {x: 0, y: 4, z: (-1)},
      {x: 0, y: 4, z: (-2)},
      {x: 0, y: 4, z: (-3)},
      {x: 1, y: 0, z: (-1)},
      {x: 1, y: 0, z: (-2)},
      {x: 1, y: 0, z: (-3)},
      {x: 1, y: 0, z: (-4)},
      {x: 1, y: 1, z: (-4)},
      {x: 1, y: 2, z: (-4)},
      {x: 1, y: 3, z: (-4)},
      {x: 1, y: 4, z: (-4)},
    ];
    myLayout
    |> List.map(c => <Cube center=c side=40 />)
    |> Array.of_list
    |> ReasonReact.arrayToElement;
  },
};