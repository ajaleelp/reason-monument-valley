let component = ReasonReact.statelessComponent("Cube");

type layout = list(Cube._3dPosition);

let make = _children => {
  ...component,
  render: _self => {
    let myLayout: layout = [{x: 0, y: 0, z: 0}, {x: 1, y: 0, z: 0}];
    myLayout
    |> List.map(c => <Cube center=c />)
    |> Array.of_list
    |> ReasonReact.arrayToElement;
  },
};