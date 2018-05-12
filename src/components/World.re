let component = ReasonReact.statelessComponent("Cube");

type layout = list(Cube._3dCoOd);

let make = _children => {
  ...component,
  render: _self => {
    let myLayout: layout = [
      {x: 0, y: 0, z: 0},
      {x: 1, y: 0, z: 0},
      {x: 1, y: 0, z: 1},
      {x: 0, y: 1, z: 0},
      {x: (-1), y: 1, z: 0},
      {x: (-1), y: 2, z: 0},
      {x: (-1), y: 2, z: 1},
    ];
    myLayout
    |> List.map(c => <Cube center=c side=40 />)
    |> Array.of_list
    |> ReasonReact.arrayToElement;
  },
};